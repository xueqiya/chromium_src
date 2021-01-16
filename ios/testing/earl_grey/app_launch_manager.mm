// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/testing/earl_grey/app_launch_manager.h"

#import <XCTest/XCTest.h>

#include "base/feature_list.h"
#import "base/ios/crb_protocol_observers.h"
#include "base/strings/sys_string_conversions.h"
#import "ios/testing/earl_grey/earl_grey_test.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

#if defined(CHROME_EARL_GREY_2)  // avoid unused function warning in EG1
namespace {
// Checks if two pairs of launch arguments are equivalent.
bool LaunchArgumentsAreEqual(NSArray<NSString*>* args1,
                             NSArray<NSString*>* args2) {
  // isEqualToArray will only return true if both arrays are non-nil,
  // so first check if both arrays are empty or nil
  if (!args1.count && !args2.count) {
    return true;
  }

  return [args1 isEqualToArray:args2];
}
}  // namespace
#endif

@interface AppLaunchManager ()
// List of observers to be notified of actions performed by the app launch
// manager.
@property(nonatomic, strong)
    CRBProtocolObservers<AppLaunchManagerObserver>* observers;
@property(nonatomic) XCUIApplication* runningApplication;
@property(nonatomic) NSArray<NSString*>* currentLaunchArgs;
@end

@implementation AppLaunchManager

+ (AppLaunchManager*)sharedManager {
  static AppLaunchManager* instance = nil;
  static dispatch_once_t guard;
  dispatch_once(&guard, ^{
    instance = [[AppLaunchManager alloc] initPrivate];
  });
  return instance;
}

- (instancetype)initPrivate {
  self = [super init];

  Protocol* protocol = @protocol(AppLaunchManagerObserver);
  _observers = (id)[CRBProtocolObservers observersWithProtocol:protocol];
  return self;
}

// Makes sure the app has been started with the appropriate |arguments|.
// In EG2, will launch the app if any of the following conditions are met:
// * The app is not running
// * The app is currently running with different arguments.
// * |forceRestart| is YES
// Otherwise, the app will be activated instead of (re)launched.
// Will wait until app is activated or launched, and fail the test if it
// fails to do so.
// In EG1, this method is a no-op.
- (void)ensureAppLaunchedWithArgs:(NSArray<NSString*>*)arguments
                   relaunchPolicy:(RelaunchPolicy)relaunchPolicy {
#if defined(CHROME_EARL_GREY_2)
  BOOL forceRestart = (relaunchPolicy == ForceRelaunchByKilling) ||
                      (relaunchPolicy == ForceRelaunchByCleanShutdown);
  BOOL gracefullyKill = (relaunchPolicy == ForceRelaunchByCleanShutdown);
  BOOL runResets = (relaunchPolicy == NoForceRelaunchAndResetState);

  bool appNeedsLaunching =
      forceRestart || !self.runningApplication ||
      !LaunchArgumentsAreEqual(arguments, self.currentLaunchArgs);

  if (!appNeedsLaunching) {
    [self.runningApplication activate];
    return;
  }

  if (self.runningApplication) {
    if (gracefullyKill) {
      GREYAssertTrue([EarlGrey backgroundApplication],
                     @"Failed to background application.");
    }
    [self.runningApplication terminate];
  }

  XCUIApplication* application = [[XCUIApplication alloc] init];
  application.launchArguments = arguments;

  [application launch];
  if (self.runningApplication) {
    [self.observers appLaunchManagerDidRelaunchApp:self runResets:runResets];
  }
  self.runningApplication = application;
  self.currentLaunchArgs = arguments;
#endif
}

- (void)ensureAppLaunchedWithConfiguration:
    (AppLaunchConfiguration)configuration {
  NSMutableArray<NSString*>* namesToEnable = [NSMutableArray array];
  NSMutableArray<NSString*>* namesToDisable = [NSMutableArray array];
  NSMutableArray<NSString*>* variations = [NSMutableArray array];

  for (const base::Feature& feature : configuration.features_enabled) {
    [namesToEnable addObject:base::SysUTF8ToNSString(feature.name)];
  }

  for (const base::Feature& feature : configuration.features_disabled) {
    [namesToDisable addObject:base::SysUTF8ToNSString(feature.name)];
  }

  for (const variations::VariationID& variation :
       configuration.variations_enabled) {
    [variations addObject:[NSString stringWithFormat:@"%d", variation]];
  }

  for (const variations::VariationID& variation :
       configuration.trigger_variations_enabled) {
    [variations addObject:[NSString stringWithFormat:@"t%d", variation]];
  }

  NSString* enabledString = @"";
  NSString* disabledString = @"";
  NSString* variationString = @"";
  if ([namesToEnable count] > 0) {
    enabledString = [NSString
        stringWithFormat:@"--enable-features=%@",
                         [namesToEnable componentsJoinedByString:@","]];
  }
  if ([namesToDisable count] > 0) {
    disabledString = [NSString
        stringWithFormat:@"--disable-features=%@",
                         [namesToDisable componentsJoinedByString:@","]];
  }
  if (variations.count > 0) {
    variationString =
        [NSString stringWithFormat:@"--force-variation-ids=%@",
                                   [variations componentsJoinedByString:@","]];
  }

  NSArray<NSString*>* arguments =
      @[ enabledString, disabledString, variationString ];

  [self ensureAppLaunchedWithArgs:arguments
                   relaunchPolicy:configuration.relaunch_policy];
}

- (void)ensureAppLaunchedWithFeaturesEnabled:
            (std::vector<base::Feature>)featuresEnabled
                                    disabled:(std::vector<base::Feature>)
                                                 featuresDisabled
                              relaunchPolicy:(RelaunchPolicy)relaunchPolicy {
  AppLaunchConfiguration config;
  config.features_enabled = std::move(featuresEnabled);
  config.features_disabled = std::move(featuresDisabled);
  config.relaunch_policy = relaunchPolicy;
  [self ensureAppLaunchedWithConfiguration:config];
}

- (void)backgroundAndForegroundApp {
#if defined(CHROME_EARL_GREY_2)
  GREYAssertTrue([EarlGrey backgroundApplication],
                 @"Failed to background application.");
  [self.runningApplication activate];
#endif
}

- (void)addObserver:(id<AppLaunchManagerObserver>)observer {
  [self.observers addObserver:observer];
}

- (void)removeObserver:(id<AppLaunchManagerObserver>)observer {
  [self.observers removeObserver:observer];
}

@end
