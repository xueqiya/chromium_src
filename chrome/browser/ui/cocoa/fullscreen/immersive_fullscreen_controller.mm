// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "chrome/browser/ui/cocoa/fullscreen/immersive_fullscreen_controller.h"

#import "base/mac/mac_util.h"
#import "chrome/browser/ui/cocoa/fullscreen/fullscreen_toolbar_controller.h"
#import "ui/base/cocoa/tracking_area.h"

namespace {

// The height from the top of the screen that will show the menubar.
const CGFloat kMenubarShowZoneHeight = 4;

// The height from the top of the screen that will hide the menubar.
// The value must be greater than the menubar's height of 22px.
const CGFloat kMenubarHideZoneHeight = 28;

}  // namespace

@interface ImmersiveFullscreenController () {
  id<FullscreenToolbarContextDelegate> _delegate;  // weak

  // Used to track the mouse movements to show/hide the menu.
  base::scoped_nsobject<CrTrackingArea> _trackingArea;

  // The content view for the window.
  NSView* _contentView;  // weak

  // Tracks the currently requested system fullscreen mode, used to show or
  // hide the menubar. Its value is as follows:
  // + |kFullScreenModeNormal| - when the window is not main or not fullscreen,
  // + |kFullScreenModeHideDock| - when the user interacts with the top of the
  // screen
  // + |kFullScreenModeHideAll| - when the conditions don't meet the first two
  // modes.
  base::mac::FullScreenMode _systemFullscreenMode;

  // True if the menubar should be shown on the screen.
  BOOL _isMenubarVisible;
}

// Whether the current screen is expected to have a menubar, regardless of
// current visibility of the menubar.
- (BOOL)doesScreenHaveMenubar;

// Adjusts the AppKit Fullscreen options of the application.
- (void)setSystemFullscreenModeTo:(base::mac::FullScreenMode)mode;

// Sets |isMenubarVisible_|. If the value has changed, update the tracking
// area, the dock, and the menubar
- (void)setMenubarVisibility:(BOOL)visible;

// Methods that update and remove the tracking area.
- (void)updateTrackingArea;
- (void)removeTrackingArea;

@end

@implementation ImmersiveFullscreenController

- (instancetype)initWithDelegate:
    (id<FullscreenToolbarContextDelegate>)delegate {
  if ((self = [super init])) {
    _delegate = delegate;
    _systemFullscreenMode = base::mac::kFullScreenModeNormal;

    _contentView = [[_delegate window] contentView];
    DCHECK(_contentView);

    _isMenubarVisible = NO;

    NSNotificationCenter* nc = [NSNotificationCenter defaultCenter];
    NSWindow* window = [_delegate window];

    [nc addObserver:self
           selector:@selector(windowDidBecomeMain:)
               name:NSWindowDidBecomeMainNotification
             object:window];

    [nc addObserver:self
           selector:@selector(windowDidResignMain:)
               name:NSWindowDidResignMainNotification
             object:window];

    [self updateTrackingArea];
  }

  return self;
}

- (void)dealloc {
  [[NSNotificationCenter defaultCenter] removeObserver:self];

  [self removeTrackingArea];
  [self setSystemFullscreenModeTo:base::mac::kFullScreenModeNormal];

  [super dealloc];
}

- (void)updateMenuBarAndDockVisibility {
  BOOL isMouseOnScreen = NSMouseInRect(
      [NSEvent mouseLocation], [[_delegate window] screen].frame, false);

  if (!isMouseOnScreen || ![_delegate isInImmersiveFullscreen])
    [self setSystemFullscreenModeTo:base::mac::kFullScreenModeNormal];
  else if ([self shouldShowMenubar])
    [self setSystemFullscreenModeTo:base::mac::kFullScreenModeHideDock];
  else
    [self setSystemFullscreenModeTo:base::mac::kFullScreenModeHideAll];
}

- (BOOL)shouldShowMenubar {
  return [self doesScreenHaveMenubar] && _isMenubarVisible;
}

- (void)windowDidBecomeMain:(NSNotification*)notification {
  [self updateMenuBarAndDockVisibility];
}

- (void)windowDidResignMain:(NSNotification*)notification {
  [self updateMenuBarAndDockVisibility];
}

- (BOOL)doesScreenHaveMenubar {
  NSScreen* screen = [[_delegate window] screen];
  NSScreen* primaryScreen = [[NSScreen screens] firstObject];
  BOOL isWindowOnPrimaryScreen = [screen isEqual:primaryScreen];

  BOOL eachScreenShouldHaveMenuBar = [NSScreen screensHaveSeparateSpaces];
  return eachScreenShouldHaveMenuBar ?: isWindowOnPrimaryScreen;
}

- (void)setSystemFullscreenModeTo:(base::mac::FullScreenMode)mode {
  if (mode == _systemFullscreenMode)
    return;

  if (_systemFullscreenMode == base::mac::kFullScreenModeNormal)
    base::mac::RequestFullScreen(mode);
  else if (mode == base::mac::kFullScreenModeNormal)
    base::mac::ReleaseFullScreen(_systemFullscreenMode);
  else
    base::mac::SwitchFullScreenModes(_systemFullscreenMode, mode);

  _systemFullscreenMode = mode;
}

- (void)setMenubarVisibility:(BOOL)visible {
  if (_isMenubarVisible == visible)
    return;

  _isMenubarVisible = visible;
  [self updateTrackingArea];
  [self updateMenuBarAndDockVisibility];
}

- (void)updateTrackingArea {
  [self removeTrackingArea];

  CGFloat trackingHeight =
      _isMenubarVisible ? kMenubarHideZoneHeight : kMenubarShowZoneHeight;
  NSRect trackingFrame = [_contentView bounds];
  trackingFrame.origin.y = NSMaxY(trackingFrame) - trackingHeight;
  trackingFrame.size.height = trackingHeight;

  // If we replace the tracking area with a new one under the cursor, the new
  // tracking area might not receive a |-mouseEntered:| or |-mouseExited| call.
  // As a result, we should also track the mouse's movements so that the
  // so the menubar won't get stuck.
  NSTrackingAreaOptions options =
      NSTrackingMouseEnteredAndExited | NSTrackingActiveInKeyWindow;
  if (_isMenubarVisible)
    options |= NSTrackingMouseMoved;

  // Create and add a new tracking area for |frame|.
  _trackingArea.reset([[CrTrackingArea alloc] initWithRect:trackingFrame
                                                   options:options
                                                     owner:self
                                                  userInfo:nil]);
  [_contentView addTrackingArea:_trackingArea];
}

- (void)removeTrackingArea {
  if (_trackingArea) {
    [_contentView removeTrackingArea:_trackingArea];
    _trackingArea.reset();
  }
}

- (void)mouseEntered:(NSEvent*)event {
  [self setMenubarVisibility:YES];
}

- (void)mouseExited:(NSEvent*)event {
  [self setMenubarVisibility:NO];
}

- (void)mouseMoved:(NSEvent*)event {
  [self setMenubarVisibility:[_trackingArea
                                 mouseInsideTrackingAreaForView:_contentView]];
}

@end
