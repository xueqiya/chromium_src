// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_UI_AUTHENTICATION_SIGNIN_SIGNIN_ENUMS_H_
#define IOS_CHROME_BROWSER_UI_AUTHENTICATION_SIGNIN_SIGNIN_ENUMS_H_

#import <Foundation/Foundation.h>

// Sign-in result returned Sign-in result.
typedef NS_ENUM(NSUInteger, SigninCoordinatorResult) {
  // Sign-in has been canceled by the user or by another reason.
  SigninCoordinatorResultCanceledByUser,
  // Sign-in has been done, but the user didn’t accept nor refuse to sync.
  SigninCoordinatorResultInterrupted,
  // Sign-in has been done, the user has been explicitly accepted or refused
  // sync.
  SigninCoordinatorResultSuccess,
};

// Action to do when the sign-in dialog needs to be interrupted.
typedef NS_ENUM(NSUInteger, SigninCoordinatorInterruptAction) {
  // Stops the sign-in coordinator without dismissing the view.
  SigninCoordinatorInterruptActionNoDismiss,
  // Stops the sign-in coordinator and dismisses the view without animation.
  SigninCoordinatorInterruptActionDismissWithoutAnimation,
  // Stops the sign-in coordinator and dismisses the view with animation.
  SigninCoordinatorInterruptActionDismissWithAnimation,
};

#endif  // IOS_CHROME_BROWSER_UI_AUTHENTICATION_SIGNIN_SIGNIN_ENUMS_H_
