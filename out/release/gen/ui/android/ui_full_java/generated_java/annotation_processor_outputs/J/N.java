package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.ui.base.Clipboard.getLastModifiedTimeToJavaTime
   * @param nativeClipboardAndroid (long)
   * @return (long)
   */
  public static final native long MN49cYVC(long nativeClipboardAndroid);

  /**
   * org.chromium.ui.base.Clipboard.onPrimaryClipChanged
   * @param nativeClipboardAndroid (long)
   * @param caller (org.chromium.ui.base.Clipboard)
   * @return (void)
   */
  public static final native void M3YqItLq(long nativeClipboardAndroid, Object caller);

  /**
   * org.chromium.ui.base.Clipboard.onPrimaryClipTimestampInvalidated
   * @param nativeClipboardAndroid (long)
   * @param caller (org.chromium.ui.base.Clipboard)
   * @param timestamp (long)
   * @return (void)
   */
  public static final native void MWrNP8sy(long nativeClipboardAndroid, Object caller,
      long timestamp);

  /**
   * org.chromium.ui.base.EventForwarder.cancelFling
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param timeMs (long)
   * @param preventBoosting (boolean)
   * @return (void)
   */
  public static final native void MSvJWvYj(long nativeEventForwarder, Object caller, long timeMs,
      boolean preventBoosting);

  /**
   * org.chromium.ui.base.EventForwarder.dispatchKeyEvent
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param event (android.view.KeyEvent)
   * @return (boolean)
   */
  public static final native boolean MZE$0qqv(long nativeEventForwarder, Object caller,
      Object event);

  /**
   * org.chromium.ui.base.EventForwarder.doubleTap
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param timeMs (long)
   * @param x (int)
   * @param y (int)
   * @return (void)
   */
  public static final native void MNnWXapV(long nativeEventForwarder, Object caller, long timeMs,
      int x, int y);

  /**
   * org.chromium.ui.base.EventForwarder.getJavaWindowAndroid
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @return (org.chromium.ui.base.WindowAndroid)
   */
  public static final native Object M4_mlka_(long nativeEventForwarder, Object caller);

  /**
   * org.chromium.ui.base.EventForwarder.onDragEvent
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param action (int)
   * @param x (int)
   * @param y (int)
   * @param screenX (int)
   * @param screenY (int)
   * @param mimeTypes (java.lang.String[])
   * @param content (java.lang.String)
   * @return (void)
   */
  public static final native void MZ1ZkPta(long nativeEventForwarder, Object caller, int action,
      int x, int y, int screenX, int screenY, String[] mimeTypes, String content);

  /**
   * org.chromium.ui.base.EventForwarder.onGenericMotionEvent
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param event (android.view.MotionEvent)
   * @param timeMs (long)
   * @return (boolean)
   */
  public static final native boolean MvdB06Zi(long nativeEventForwarder, Object caller,
      Object event, long timeMs);

  /**
   * org.chromium.ui.base.EventForwarder.onGestureEvent
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param type (int)
   * @param timeMs (long)
   * @param delta (float)
   * @return (boolean)
   */
  public static final native boolean MtyC4Bd2(long nativeEventForwarder, Object caller, int type,
      long timeMs, float delta);

  /**
   * org.chromium.ui.base.EventForwarder.onKeyUp
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param event (android.view.KeyEvent)
   * @param keyCode (int)
   * @return (boolean)
   */
  public static final native boolean MRbfSEI1(long nativeEventForwarder, Object caller,
      Object event, int keyCode);

  /**
   * org.chromium.ui.base.EventForwarder.onMouseEvent
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param timeMs (long)
   * @param action (int)
   * @param x (float)
   * @param y (float)
   * @param pointerId (int)
   * @param pressure (float)
   * @param orientation (float)
   * @param tilt (float)
   * @param changedButton (int)
   * @param buttonState (int)
   * @param metaState (int)
   * @param toolType (int)
   * @return (void)
   */
  public static final native void M$2oj6EQ(long nativeEventForwarder, Object caller, long timeMs,
      int action, float x, float y, int pointerId, float pressure, float orientation, float tilt,
      int changedButton, int buttonState, int metaState, int toolType);

  /**
   * org.chromium.ui.base.EventForwarder.onTouchEvent
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param event (android.view.MotionEvent)
   * @param timeMs (long)
   * @param action (int)
   * @param pointerCount (int)
   * @param historySize (int)
   * @param actionIndex (int)
   * @param x0 (float)
   * @param y0 (float)
   * @param x1 (float)
   * @param y1 (float)
   * @param pointerId0 (int)
   * @param pointerId1 (int)
   * @param touchMajor0 (float)
   * @param touchMajor1 (float)
   * @param touchMinor0 (float)
   * @param touchMinor1 (float)
   * @param orientation0 (float)
   * @param orientation1 (float)
   * @param tilt0 (float)
   * @param tilt1 (float)
   * @param rawX (float)
   * @param rawY (float)
   * @param androidToolType0 (int)
   * @param androidToolType1 (int)
   * @param androidButtonState (int)
   * @param androidMetaState (int)
   * @param isTouchHandleEvent (boolean)
   * @return (boolean)
   */
  public static final native boolean Mcw1yi1C(long nativeEventForwarder, Object caller,
      Object event, long timeMs, int action, int pointerCount, int historySize, int actionIndex,
      float x0, float y0, float x1, float y1, int pointerId0, int pointerId1, float touchMajor0,
      float touchMajor1, float touchMinor0, float touchMinor1, float orientation0,
      float orientation1, float tilt0, float tilt1, float rawX, float rawY, int androidToolType0,
      int androidToolType1, int androidButtonState, int androidMetaState,
      boolean isTouchHandleEvent);

  /**
   * org.chromium.ui.base.EventForwarder.scrollBy
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param deltaX (float)
   * @param deltaY (float)
   * @return (void)
   */
  public static final native void MMwH$VBb(long nativeEventForwarder, Object caller, float deltaX,
      float deltaY);

  /**
   * org.chromium.ui.base.EventForwarder.scrollTo
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param x (float)
   * @param y (float)
   * @return (void)
   */
  public static final native void M6lTZ5w8(long nativeEventForwarder, Object caller, float x,
      float y);

  /**
   * org.chromium.ui.base.EventForwarder.startFling
   * @param nativeEventForwarder (long)
   * @param caller (org.chromium.ui.base.EventForwarder)
   * @param timeMs (long)
   * @param velocityX (float)
   * @param velocityY (float)
   * @param syntheticScroll (boolean)
   * @param preventBoosting (boolean)
   * @return (void)
   */
  public static final native void MT1C98PL(long nativeEventForwarder, Object caller, long timeMs,
      float velocityX, float velocityY, boolean syntheticScroll, boolean preventBoosting);

  /**
   * org.chromium.ui.base.LocalizationUtils.getFirstStrongCharacterDirection
   * @param string (java.lang.String)
   * @return (int)
   */
  public static final native int MKiziH$q(String string);

  /**
   * org.chromium.ui.base.SelectFileDialog.onContactsSelected
   * @param nativeSelectFileDialogImpl (long)
   * @param caller (org.chromium.ui.base.SelectFileDialog)
   * @param contacts (java.lang.String)
   * @return (void)
   */
  public static final native void MXucAq1Y(long nativeSelectFileDialogImpl, Object caller,
      String contacts);

  /**
   * org.chromium.ui.base.SelectFileDialog.onFileNotSelected
   * @param nativeSelectFileDialogImpl (long)
   * @param caller (org.chromium.ui.base.SelectFileDialog)
   * @return (void)
   */
  public static final native void MGVJOCWv(long nativeSelectFileDialogImpl, Object caller);

  /**
   * org.chromium.ui.base.SelectFileDialog.onFileSelected
   * @param nativeSelectFileDialogImpl (long)
   * @param caller (org.chromium.ui.base.SelectFileDialog)
   * @param filePath (java.lang.String)
   * @param displayName (java.lang.String)
   * @return (void)
   */
  public static final native void MBeWYy2V(long nativeSelectFileDialogImpl, Object caller,
      String filePath, String displayName);

  /**
   * org.chromium.ui.base.SelectFileDialog.onMultipleFilesSelected
   * @param nativeSelectFileDialogImpl (long)
   * @param caller (org.chromium.ui.base.SelectFileDialog)
   * @param filePathArray (java.lang.String[])
   * @param displayNameArray (java.lang.String[])
   * @return (void)
   */
  public static final native void Mx1807vz(long nativeSelectFileDialogImpl, Object caller,
      String[] filePathArray, String[] displayNameArray);

  /**
   * org.chromium.ui.base.WindowAndroid.destroy
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @return (void)
   */
  public static final native void MV00Qksi(long nativeWindowAndroid, Object caller);

  /**
   * org.chromium.ui.base.WindowAndroid.init
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param displayId (int)
   * @param scrollFactor (float)
   * @param windowIsWideColorGamut (boolean)
   * @return (long)
   */
  public static final native long MFjTMMS_(Object caller, int displayId, float scrollFactor,
      boolean windowIsWideColorGamut);

  /**
   * org.chromium.ui.base.WindowAndroid.onActivityStarted
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @return (void)
   */
  public static final native void MbyUPhMo(long nativeWindowAndroid, Object caller);

  /**
   * org.chromium.ui.base.WindowAndroid.onActivityStopped
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @return (void)
   */
  public static final native void MMLuxHp6(long nativeWindowAndroid, Object caller);

  /**
   * org.chromium.ui.base.WindowAndroid.onCursorVisibilityChanged
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param visible (boolean)
   * @return (void)
   */
  public static final native void ML$dVqbX(long nativeWindowAndroid, Object caller,
      boolean visible);

  /**
   * org.chromium.ui.base.WindowAndroid.onFallbackCursorModeToggled
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param isOn (boolean)
   * @return (void)
   */
  public static final native void Mpksm6S7(long nativeWindowAndroid, Object caller, boolean isOn);

  /**
   * org.chromium.ui.base.WindowAndroid.onSupportedRefreshRatesUpdated
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param supportedRefreshRates (float[])
   * @return (void)
   */
  public static final native void MTDQeb$o(long nativeWindowAndroid, Object caller,
      float[] supportedRefreshRates);

  /**
   * org.chromium.ui.base.WindowAndroid.onUpdateRefreshRate
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param refreshRate (float)
   * @return (void)
   */
  public static final native void MWNjxKcW(long nativeWindowAndroid, Object caller,
      float refreshRate);

  /**
   * org.chromium.ui.base.WindowAndroid.onVisibilityChanged
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param visible (boolean)
   * @return (void)
   */
  public static final native void MrnNdVRa(long nativeWindowAndroid, Object caller,
      boolean visible);

  /**
   * org.chromium.ui.base.WindowAndroid.setVSyncPaused
   * @param nativeWindowAndroid (long)
   * @param caller (org.chromium.ui.base.WindowAndroid)
   * @param paused (boolean)
   * @return (void)
   */
  public static final native void MotttR54(long nativeWindowAndroid, Object caller, boolean paused);

  /**
   * org.chromium.ui.display.DisplayAndroidManager.removeDisplay
   * @param nativeDisplayAndroidManager (long)
   * @param caller (org.chromium.ui.display.DisplayAndroidManager)
   * @param sdkDisplayId (int)
   * @return (void)
   */
  public static final native void MyzQIqd_(long nativeDisplayAndroidManager, Object caller,
      int sdkDisplayId);

  /**
   * org.chromium.ui.display.DisplayAndroidManager.setPrimaryDisplayId
   * @param nativeDisplayAndroidManager (long)
   * @param caller (org.chromium.ui.display.DisplayAndroidManager)
   * @param sdkDisplayId (int)
   * @return (void)
   */
  public static final native void MdOwtyr6(long nativeDisplayAndroidManager, Object caller,
      int sdkDisplayId);

  /**
   * org.chromium.ui.display.DisplayAndroidManager.updateDisplay
   * @param nativeDisplayAndroidManager (long)
   * @param caller (org.chromium.ui.display.DisplayAndroidManager)
   * @param sdkDisplayId (int)
   * @param width (int)
   * @param height (int)
   * @param dipScale (float)
   * @param rotationDegrees (int)
   * @param bitsPerPixel (int)
   * @param bitsPerComponent (int)
   * @param isWideColorGamut (boolean)
   * @return (void)
   */
  public static final native void M2$ANfTC(long nativeDisplayAndroidManager, Object caller,
      int sdkDisplayId, int width, int height, float dipScale, int rotationDegrees,
      int bitsPerPixel, int bitsPerComponent, boolean isWideColorGamut);

  /**
   * org.chromium.ui.events.devices.InputDeviceObserver.inputConfigurationChanged
   * @param caller (org.chromium.ui.events.devices.InputDeviceObserver)
   * @return (void)
   */
  public static final native void MGCvz8lp(Object caller);

  /**
   * org.chromium.ui.gfx.ViewConfigurationHelper.updateSharedViewConfiguration
   * @param caller (org.chromium.ui.gfx.ViewConfigurationHelper)
   * @param maximumFlingVelocity (float)
   * @param minimumFlingVelocity (float)
   * @param touchSlop (float)
   * @param doubleTapSlop (float)
   * @param minScalingSpan (float)
   * @return (void)
   */
  public static final native void MtrEpb2R(Object caller, float maximumFlingVelocity,
      float minimumFlingVelocity, float touchSlop, float doubleTapSlop, float minScalingSpan);

  /**
   * org.chromium.ui.gl.SurfaceTextureListener.destroy
   * @param nativeSurfaceTextureListener (long)
   * @param caller (org.chromium.ui.gl.SurfaceTextureListener)
   * @return (void)
   */
  public static final native void MUH2vhAN(long nativeSurfaceTextureListener, Object caller);

  /**
   * org.chromium.ui.gl.SurfaceTextureListener.frameAvailable
   * @param nativeSurfaceTextureListener (long)
   * @param caller (org.chromium.ui.gl.SurfaceTextureListener)
   * @return (void)
   */
  public static final native void MRbPfCZQ(long nativeSurfaceTextureListener, Object caller);

  /**
   * org.chromium.ui.resources.ResourceFactory.createBitmapResource
   * @return (long)
   */
  public static final native long MKzrMxwv();

  /**
   * org.chromium.ui.resources.ResourceFactory.createNinePatchBitmapResource
   * @param paddingLeft (int)
   * @param paddingTop (int)
   * @param paddingRight (int)
   * @param paddingBottom (int)
   * @param apertureLeft (int)
   * @param apertureTop (int)
   * @param apertureRight (int)
   * @param apertureBottom (int)
   * @return (long)
   */
  public static final native long MNZCYawX(int paddingLeft, int paddingTop, int paddingRight,
      int paddingBottom, int apertureLeft, int apertureTop, int apertureRight, int apertureBottom);

  /**
   * org.chromium.ui.resources.ResourceManager.clearTintedResourceCache
   * @param nativeResourceManagerImpl (long)
   * @param caller (org.chromium.ui.resources.ResourceManager)
   * @return (void)
   */
  public static final native void MnAVuP1v(long nativeResourceManagerImpl, Object caller);

  /**
   * org.chromium.ui.resources.ResourceManager.onResourceReady
   * @param nativeResourceManagerImpl (long)
   * @param caller (org.chromium.ui.resources.ResourceManager)
   * @param resType (int)
   * @param resId (int)
   * @param bitmap (android.graphics.Bitmap)
   * @param width (int)
   * @param height (int)
   * @param nativeResource (long)
   * @return (void)
   */
  public static final native void MM7E4tBk(long nativeResourceManagerImpl, Object caller,
      int resType, int resId, Object bitmap, int width, int height, long nativeResource);

  /**
   * org.chromium.ui.resources.ResourceManager.removeResource
   * @param nativeResourceManagerImpl (long)
   * @param caller (org.chromium.ui.resources.ResourceManager)
   * @param resType (int)
   * @param resId (int)
   * @return (void)
   */
  public static final native void MxwZmAzJ(long nativeResourceManagerImpl, Object caller,
      int resType, int resId);
}
