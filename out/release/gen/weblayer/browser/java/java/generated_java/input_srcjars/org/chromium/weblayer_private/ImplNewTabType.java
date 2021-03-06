
// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     java_cpp_enum.py
// From
//     ../../weblayer/public/new_tab_delegate.h

package org.chromium.weblayer_private;

import androidx.annotation.IntDef;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@IntDef({
    ImplNewTabType.FOREGROUND, ImplNewTabType.BACKGROUND, ImplNewTabType.NEW_POPUP,
    ImplNewTabType.NEW_WINDOW
})
@Retention(RetentionPolicy.SOURCE)
public @interface ImplNewTabType {
  /**
   * The new browser should be opened in the foreground.
   */
  int FOREGROUND = 0;
  /**
   * The new browser should be opened in the foreground.
   */
  int BACKGROUND = 1;
  /**
   * The page requested the browser be shown in a new window with minimal browser UI. For example,
   * no tabstrip.
   */
  int NEW_POPUP = 2;
  /**
   * The page requested the browser be shown in a new window.
   */
  int NEW_WINDOW = 3;
}
