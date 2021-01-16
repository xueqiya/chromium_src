package J;

import java.lang.Class;
import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.content.app.ContentChildProcessServiceDelegate.initChildProcess
   * @param caller (org.chromium.content.app.ContentChildProcessServiceDelegate)
   * @param cpuCount (int)
   * @param cpuFeatures (long)
   * @return (void)
   */
  public static final native void MBlO3kR9(Object caller, int cpuCount, long cpuFeatures);

  /**
   * org.chromium.content.app.ContentChildProcessServiceDelegate.retrieveFileDescriptorsIdsToKeys
   * @param caller (org.chromium.content.app.ContentChildProcessServiceDelegate)
   * @return (void)
   */
  public static final native void M0zXFFiu(Object caller);

  /**
   * org.chromium.content.app.ContentMain.start
   * @param startServiceManagerOnly (boolean)
   * @return (int)
   */
  public static final native int M1Y_XVCN(boolean startServiceManagerOnly);

  /**
   * org.chromium.content.browser.AppWebMessagePort.decodeStringMessage
   * @param encodedData (byte[])
   * @return (java.lang.String)
   */
  public static final native String MWL_OG7s(byte[] encodedData);

  /**
   * org.chromium.content.browser.AppWebMessagePort.encodeStringMessage
   * @param message (java.lang.String)
   * @return (byte[])
   */
  public static final native byte[] Mk6SEKCp(String message);

  /**
   * org.chromium.content.browser.AppWebMessagePortDescriptor.closeAndDestroy
   * @param blinkMessagePortDescriptor (long)
   * @return (void)
   */
  public static final native void MWkkqfl2(long blinkMessagePortDescriptor);

  /**
   * org.chromium.content.browser.AppWebMessagePortDescriptor.create
   * @param nativeHandle (int)
   * @param idLow (long)
   * @param idHigh (long)
   * @param sequenceNumber (long)
   * @return (long)
   */
  public static final native long MsjrrfZt(int nativeHandle, long idLow, long idHigh,
      long sequenceNumber);

  /**
   * org.chromium.content.browser.AppWebMessagePortDescriptor.createPair
   * @return (long[])
   */
  public static final native long[] MZ2WfWkn();

  /**
   * org.chromium.content.browser.AppWebMessagePortDescriptor.giveDisentangledHandle
   * @param blinkMessagePortDescriptor (long)
   * @param nativeHandle (int)
   * @return (void)
   */
  public static final native void MylsTJ$B(long blinkMessagePortDescriptor, int nativeHandle);

  /**
   * org.chromium.content.browser.AppWebMessagePortDescriptor.passSerialized
   * @param blinkMessagePortDescriptor (long)
   * @return (long[])
   */
  public static final native long[] MJJP$CQY(long blinkMessagePortDescriptor);

  /**
   * org.chromium.content.browser.AppWebMessagePortDescriptor.takeHandleToEntangle
   * @param blinkMessagePortDescriptor (long)
   * @return (int)
   */
  public static final native int MbOQIpGw(long blinkMessagePortDescriptor);

  /**
   * org.chromium.content.browser.AudioFocusDelegate.onResume
   * @param nativeAudioFocusDelegateAndroid (long)
   * @param caller (org.chromium.content.browser.AudioFocusDelegate)
   * @return (void)
   */
  public static final native void MqbF3KiE(long nativeAudioFocusDelegateAndroid, Object caller);

  /**
   * org.chromium.content.browser.AudioFocusDelegate.onStartDucking
   * @param nativeAudioFocusDelegateAndroid (long)
   * @param caller (org.chromium.content.browser.AudioFocusDelegate)
   * @return (void)
   */
  public static final native void My_SIOp6(long nativeAudioFocusDelegateAndroid, Object caller);

  /**
   * org.chromium.content.browser.AudioFocusDelegate.onStopDucking
   * @param nativeAudioFocusDelegateAndroid (long)
   * @param caller (org.chromium.content.browser.AudioFocusDelegate)
   * @return (void)
   */
  public static final native void MeoE5HbI(long nativeAudioFocusDelegateAndroid, Object caller);

  /**
   * org.chromium.content.browser.AudioFocusDelegate.onSuspend
   * @param nativeAudioFocusDelegateAndroid (long)
   * @param caller (org.chromium.content.browser.AudioFocusDelegate)
   * @return (void)
   */
  public static final native void MUFA7yj7(long nativeAudioFocusDelegateAndroid, Object caller);

  /**
   * org.chromium.content.browser.AudioFocusDelegate.recordSessionDuck
   * @param nativeAudioFocusDelegateAndroid (long)
   * @param caller (org.chromium.content.browser.AudioFocusDelegate)
   * @return (void)
   */
  public static final native void Mn3dG6eh(long nativeAudioFocusDelegateAndroid, Object caller);

  /**
   * org.chromium.content.browser.BackgroundSyncNetworkObserver.notifyConnectionTypeChanged
   * @param nativePtr (long)
   * @param caller (org.chromium.content.browser.BackgroundSyncNetworkObserver)
   * @param newConnectionType (int)
   * @return (void)
   */
  public static final native void MJIG3QvD(long nativePtr, Object caller, int newConnectionType);

  /**
   * org.chromium.content.browser.BrowserStartupControllerImpl.flushStartupTasks
   * @return (void)
   */
  public static final native void M9iLjy6T();

  /**
   * org.chromium.content.browser.BrowserStartupControllerImpl.isOfficialBuild
   * @return (boolean)
   */
  public static final native boolean MT$iIjxT();

  /**
   * org.chromium.content.browser.BrowserStartupControllerImpl.setCommandLineFlags
   * @param singleProcess (boolean)
   * @return (void)
   */
  public static final native void MwoPtAzD(boolean singleProcess);

  /**
   * org.chromium.content.browser.ChildProcessLauncherHelperImpl.onChildProcessStarted
   * @param nativeChildProcessLauncherHelper (long)
   * @param pid (int)
   * @return (void)
   */
  public static final native void MXR$KaDS(long nativeChildProcessLauncherHelper, int pid);

  /**
   * org.chromium.content.browser.ChildProcessLauncherHelperImpl.setTerminationInfo
   * @param termiantionInfoPtr (long)
   * @param bindingState (int)
   * @param killedByUs (boolean)
   * @param cleanExit (boolean)
   * @param remainingStrong (int)
   * @param remainingModerate (int)
   * @param remainingWaived (int)
   * @param reverseRank (int)
   * @return (void)
   */
  public static final native void MJcoZ9pW(long termiantionInfoPtr, int bindingState,
      boolean killedByUs, boolean cleanExit, int remainingStrong, int remainingModerate,
      int remainingWaived, int reverseRank);

  /**
   * org.chromium.content.browser.ContactsDialogHost.addContact
   * @param nativeContactsProviderAndroid (long)
   * @param names (java.lang.String[])
   * @param emails (java.lang.String[])
   * @param tel (java.lang.String[])
   * @param addresses (java.nio.ByteBuffer[])
   * @param icons (java.nio.ByteBuffer[])
   * @return (void)
   */
  public static final native void MS9BZrW0(long nativeContactsProviderAndroid, String[] names,
      String[] emails, String[] tel, Object[] addresses, Object[] icons);

  /**
   * org.chromium.content.browser.ContactsDialogHost.endContactsList
   * @param nativeContactsProviderAndroid (long)
   * @param percentageShared (int)
   * @param propertiesRequested (int)
   * @return (void)
   */
  public static final native void MwwTaBAE(long nativeContactsProviderAndroid, int percentageShared,
      int propertiesRequested);

  /**
   * org.chromium.content.browser.ContactsDialogHost.endWithPermissionDenied
   * @param nativeContactsProviderAndroid (long)
   * @return (void)
   */
  public static final native void MOM50EIZ(long nativeContactsProviderAndroid);

  /**
   * org.chromium.content.browser.ContentFeatureListImpl.isEnabled
   * @param featureName (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean Mudil8Bg(String featureName);

  /**
   * org.chromium.content.browser.ContentUiEventHandler.cancelFling
   * @param nativeContentUiEventHandler (long)
   * @param caller (org.chromium.content.browser.ContentUiEventHandler)
   * @param timeMs (long)
   * @return (void)
   */
  public static final native void MW$k83qi(long nativeContentUiEventHandler, Object caller,
      long timeMs);

  /**
   * org.chromium.content.browser.ContentUiEventHandler.init
   * @param caller (org.chromium.content.browser.ContentUiEventHandler)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long MXL6itCa(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.ContentUiEventHandler.sendMouseEvent
   * @param nativeContentUiEventHandler (long)
   * @param caller (org.chromium.content.browser.ContentUiEventHandler)
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
  public static final native void MjyjK8Gd(long nativeContentUiEventHandler, Object caller,
      long timeMs, int action, float x, float y, int pointerId, float pressure, float orientation,
      float tilt, int changedButton, int buttonState, int metaState, int toolType);

  /**
   * org.chromium.content.browser.ContentUiEventHandler.sendMouseWheelEvent
   * @param nativeContentUiEventHandler (long)
   * @param caller (org.chromium.content.browser.ContentUiEventHandler)
   * @param timeMs (long)
   * @param x (float)
   * @param y (float)
   * @param ticksX (float)
   * @param ticksY (float)
   * @return (void)
   */
  public static final native void MifdK0lh(long nativeContentUiEventHandler, Object caller,
      long timeMs, float x, float y, float ticksX, float ticksY);

  /**
   * org.chromium.content.browser.ContentUiEventHandler.sendScrollEvent
   * @param nativeContentUiEventHandler (long)
   * @param caller (org.chromium.content.browser.ContentUiEventHandler)
   * @param timeMs (long)
   * @param deltaX (float)
   * @param deltaY (float)
   * @return (void)
   */
  public static final native void M_1sgTVt(long nativeContentUiEventHandler, Object caller,
      long timeMs, float deltaX, float deltaY);

  /**
   * org.chromium.content.browser.ContentViewStaticsImpl.setWebKitSharedTimersSuspended
   * @param suspend (boolean)
   * @return (void)
   */
  public static final native void M556jcRe(boolean suspend);

  /**
   * org.chromium.content.browser.GestureListenerManagerImpl.init
   * @param caller (org.chromium.content.browser.GestureListenerManagerImpl)
   * @param webContents (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (long)
   */
  public static final native long MefCIE9S(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.GestureListenerManagerImpl.resetGestureDetection
   * @param nativeGestureListenerManager (long)
   * @param caller (org.chromium.content.browser.GestureListenerManagerImpl)
   * @return (void)
   */
  public static final native void MMR0DKoy(long nativeGestureListenerManager, Object caller);

  /**
   * org.chromium.content.browser.GestureListenerManagerImpl.setDoubleTapSupportEnabled
   * @param nativeGestureListenerManager (long)
   * @param caller (org.chromium.content.browser.GestureListenerManagerImpl)
   * @param enabled (boolean)
   * @return (void)
   */
  public static final native void MrZmTSS9(long nativeGestureListenerManager, Object caller,
      boolean enabled);

  /**
   * org.chromium.content.browser.GestureListenerManagerImpl.setMultiTouchZoomSupportEnabled
   * @param nativeGestureListenerManager (long)
   * @param caller (org.chromium.content.browser.GestureListenerManagerImpl)
   * @param enabled (boolean)
   * @return (void)
   */
  public static final native void M6a5zchR(long nativeGestureListenerManager, Object caller,
      boolean enabled);

  /**
   * org.chromium.content.browser.GpuProcessCallback.completeScopedSurfaceRequest
   * @param requestToken (org.chromium.base.UnguessableToken)
   * @param surface (android.view.Surface)
   * @return (void)
   */
  public static final native void M$O7xE3y(Object requestToken, Object surface);

  /**
   * org.chromium.content.browser.GpuProcessCallback.getViewSurface
   * @param surfaceId (int)
   * @return (org.chromium.content.common.SurfaceWrapper)
   */
  public static final native Object Mm9rCM0m(int surfaceId);

  /**
   * org.chromium.content.browser.JavascriptInjectorImpl.addInterface
   * @param nativeJavascriptInjector (long)
   * @param caller (org.chromium.content.browser.JavascriptInjectorImpl)
   * @param object (java.lang.Object)
   * @param name (java.lang.String)
   * @param requiredAnnotation (java.lang.Class)
   * @return (void)
   */
  public static final native void Mpa5DCUY(long nativeJavascriptInjector, Object caller,
      Object object, String name, Class requiredAnnotation);

  /**
   * org.chromium.content.browser.JavascriptInjectorImpl.init
   * @param caller (org.chromium.content.browser.JavascriptInjectorImpl)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @param retainedObjects (java.lang.Object)
   * @return (long)
   */
  public static final native long MaMB25XA(Object caller, Object webContents,
      Object retainedObjects);

  /**
   * org.chromium.content.browser.JavascriptInjectorImpl.removeInterface
   * @param nativeJavascriptInjector (long)
   * @param caller (org.chromium.content.browser.JavascriptInjectorImpl)
   * @param name (java.lang.String)
   * @return (void)
   */
  public static final native void M5J62vXh(long nativeJavascriptInjector, Object caller,
      String name);

  /**
   * org.chromium.content.browser.JavascriptInjectorImpl.setAllowInspection
   * @param nativeJavascriptInjector (long)
   * @param caller (org.chromium.content.browser.JavascriptInjectorImpl)
   * @param allow (boolean)
   * @return (void)
   */
  public static final native void M9VsdpoI(long nativeJavascriptInjector, Object caller,
      boolean allow);

  /**
   * org.chromium.content.browser.MediaSessionImpl.didReceiveAction
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @param action (int)
   * @return (void)
   */
  public static final native void MAqRqyJa(long nativeMediaSessionAndroid, Object caller,
      int action);

  /**
   * org.chromium.content.browser.MediaSessionImpl.getMediaSessionFromWebContents
   * @param contents (org.chromium.content_public.browser.WebContents)
   * @return (org.chromium.content.browser.MediaSessionImpl)
   */
  public static final native Object Mtun$qW8(Object contents);

  /**
   * org.chromium.content.browser.MediaSessionImpl.requestSystemAudioFocus
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @return (void)
   */
  public static final native void MdnoDrDw(long nativeMediaSessionAndroid, Object caller);

  /**
   * org.chromium.content.browser.MediaSessionImpl.resume
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @return (void)
   */
  public static final native void MlezJYnz(long nativeMediaSessionAndroid, Object caller);

  /**
   * org.chromium.content.browser.MediaSessionImpl.seek
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @param millis (long)
   * @return (void)
   */
  public static final native void My_T5ZML(long nativeMediaSessionAndroid, Object caller,
      long millis);

  /**
   * org.chromium.content.browser.MediaSessionImpl.seekTo
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @param millis (long)
   * @return (void)
   */
  public static final native void MK7btVfc(long nativeMediaSessionAndroid, Object caller,
      long millis);

  /**
   * org.chromium.content.browser.MediaSessionImpl.stop
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @return (void)
   */
  public static final native void MW5s36cs(long nativeMediaSessionAndroid, Object caller);

  /**
   * org.chromium.content.browser.MediaSessionImpl.suspend
   * @param nativeMediaSessionAndroid (long)
   * @param caller (org.chromium.content.browser.MediaSessionImpl)
   * @return (void)
   */
  public static final native void M5LC9gX$(long nativeMediaSessionAndroid, Object caller);

  /**
   * org.chromium.content.browser.RenderWidgetHostViewImpl.dismissTextHandles
   * @param nativeRenderWidgetHostViewAndroid (long)
   * @param caller (org.chromium.content.browser.RenderWidgetHostViewImpl)
   * @return (void)
   */
  public static final native void MQWja$xA(long nativeRenderWidgetHostViewAndroid, Object caller);

  /**
   * org.chromium.content.browser.RenderWidgetHostViewImpl.getBackgroundColor
   * @param nativeRenderWidgetHostViewAndroid (long)
   * @param caller (org.chromium.content.browser.RenderWidgetHostViewImpl)
   * @return (int)
   */
  public static final native int MRWsmoin(long nativeRenderWidgetHostViewAndroid, Object caller);

  /**
   * org.chromium.content.browser.RenderWidgetHostViewImpl.isReady
   * @param nativeRenderWidgetHostViewAndroid (long)
   * @param caller (org.chromium.content.browser.RenderWidgetHostViewImpl)
   * @return (boolean)
   */
  public static final native boolean MZn2HluM(long nativeRenderWidgetHostViewAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.RenderWidgetHostViewImpl.onViewportInsetBottomChanged
   * @param nativeRenderWidgetHostViewAndroid (long)
   * @param caller (org.chromium.content.browser.RenderWidgetHostViewImpl)
   * @return (void)
   */
  public static final native void Myd8R_Wn(long nativeRenderWidgetHostViewAndroid, Object caller);

  /**
   * org.chromium.content.browser.RenderWidgetHostViewImpl.showContextMenuAtTouchHandle
   * @param nativeRenderWidgetHostViewAndroid (long)
   * @param caller (org.chromium.content.browser.RenderWidgetHostViewImpl)
   * @param x (int)
   * @param y (int)
   * @return (void)
   */
  public static final native void McU85DFE(long nativeRenderWidgetHostViewAndroid, Object caller,
      int x, int y);

  /**
   * org.chromium.content.browser.RenderWidgetHostViewImpl.writeContentBitmapToDiskAsync
   * @param nativeRenderWidgetHostViewAndroid (long)
   * @param caller (org.chromium.content.browser.RenderWidgetHostViewImpl)
   * @param width (int)
   * @param height (int)
   * @param path (java.lang.String)
   * @param callback (org.chromium.base.Callback<java.lang.String>)
   * @return (void)
   */
  public static final native void Mjmv7RJS(long nativeRenderWidgetHostViewAndroid, Object caller,
      int width, int height, String path, Object callback);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onAudioEnd
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @return (void)
   */
  public static final native void M2TRi32V(long nativeSpeechRecognizerImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onAudioStart
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @return (void)
   */
  public static final native void MdhaXGcn(long nativeSpeechRecognizerImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onRecognitionEnd
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @return (void)
   */
  public static final native void MmgQYR9M(long nativeSpeechRecognizerImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onRecognitionError
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @param error (int)
   * @return (void)
   */
  public static final native void MUf_fHKN(long nativeSpeechRecognizerImplAndroid, Object caller,
      int error);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onRecognitionResults
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @param results (java.lang.String[])
   * @param scores (float[])
   * @param provisional (boolean)
   * @return (void)
   */
  public static final native void MnkvkoGY(long nativeSpeechRecognizerImplAndroid, Object caller,
      String[] results, float[] scores, boolean provisional);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onSoundEnd
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @return (void)
   */
  public static final native void MFB2QCbe(long nativeSpeechRecognizerImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.SpeechRecognitionImpl.onSoundStart
   * @param nativeSpeechRecognizerImplAndroid (long)
   * @param caller (org.chromium.content.browser.SpeechRecognitionImpl)
   * @return (void)
   */
  public static final native void M2Nl8ID9(long nativeSpeechRecognizerImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.destroy
   * @param nativeTracingControllerAndroid (long)
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @return (void)
   */
  public static final native void MLYQdwUF(long nativeTracingControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.getDefaultCategories
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @return (java.lang.String)
   */
  public static final native String My9pNx9O(Object caller);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.getKnownCategoriesAsync
   * @param nativeTracingControllerAndroid (long)
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @param callback (org.chromium.base.Callback<java.lang.String[]>)
   * @return (boolean)
   */
  public static final native boolean MdRNuqnW(long nativeTracingControllerAndroid, Object caller,
      Object callback);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.getTraceBufferUsageAsync
   * @param nativeTracingControllerAndroid (long)
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @param callback (org.chromium.base.Callback<android.util.Pair<java.lang.Float, java.lang.Long>>)
   * @return (boolean)
   */
  public static final native boolean MkLMghix(long nativeTracingControllerAndroid, Object caller,
      Object callback);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.init
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @return (long)
   */
  public static final native long MWlLnA$6(Object caller);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.startTracing
   * @param nativeTracingControllerAndroid (long)
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @param categories (java.lang.String)
   * @param traceOptions (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MZYMIGWv(long nativeTracingControllerAndroid, Object caller,
      String categories, String traceOptions);

  /**
   * org.chromium.content.browser.TracingControllerAndroidImpl.stopTracing
   * @param nativeTracingControllerAndroid (long)
   * @param caller (org.chromium.content.browser.TracingControllerAndroidImpl)
   * @param filename (java.lang.String)
   * @param compressFile (boolean)
   * @param callback (org.chromium.base.Callback<java.lang.Void>)
   * @return (void)
   */
  public static final native void M$HKWu8q(long nativeTracingControllerAndroid, Object caller,
      String filename, boolean compressFile, Object callback);

  /**
   * org.chromium.content.browser.TtsPlatformImpl.onEndEvent
   * @param nativeTtsPlatformImplAndroid (long)
   * @param caller (org.chromium.content.browser.TtsPlatformImpl)
   * @param utteranceId (int)
   * @return (void)
   */
  public static final native void M47GdBO5(long nativeTtsPlatformImplAndroid, Object caller,
      int utteranceId);

  /**
   * org.chromium.content.browser.TtsPlatformImpl.onErrorEvent
   * @param nativeTtsPlatformImplAndroid (long)
   * @param caller (org.chromium.content.browser.TtsPlatformImpl)
   * @param utteranceId (int)
   * @return (void)
   */
  public static final native void M1Kw17GB(long nativeTtsPlatformImplAndroid, Object caller,
      int utteranceId);

  /**
   * org.chromium.content.browser.TtsPlatformImpl.onStartEvent
   * @param nativeTtsPlatformImplAndroid (long)
   * @param caller (org.chromium.content.browser.TtsPlatformImpl)
   * @param utteranceId (int)
   * @return (void)
   */
  public static final native void M2$X0reE(long nativeTtsPlatformImplAndroid, Object caller,
      int utteranceId);

  /**
   * org.chromium.content.browser.TtsPlatformImpl.requestTtsStop
   * @param nativeTtsPlatformImplAndroid (long)
   * @param caller (org.chromium.content.browser.TtsPlatformImpl)
   * @return (void)
   */
  public static final native void M0BAvNEw(long nativeTtsPlatformImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.TtsPlatformImpl.voicesChanged
   * @param nativeTtsPlatformImplAndroid (long)
   * @param caller (org.chromium.content.browser.TtsPlatformImpl)
   * @return (void)
   */
  public static final native void MpJkwIUo(long nativeTtsPlatformImplAndroid, Object caller);

  /**
   * org.chromium.content.browser.accessibility.BrowserAccessibilityState.onAnimatorDurationScaleChanged
   * @return (void)
   */
  public static final native void MAa7bxOG();

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.addSpellingErrorForTesting
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @param startOffset (int)
   * @param endOffset (int)
   * @return (void)
   */
  public static final native void MzygGmQh(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id, int startOffset, int endOffset);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.adjustSlider
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @param increment (boolean)
   * @return (boolean)
   */
  public static final native boolean MLjXc4lw(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id, boolean increment);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.areInlineTextBoxesLoaded
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean MZcfOSQW(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.blur
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (void)
   */
  public static final native void MNm00fYN(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.click
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (void)
   */
  public static final native void MM4OAOXm(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.deleteEarly
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @return (void)
   */
  public static final native void MxGfnb$m(long nativeWebContentsAccessibilityAndroid);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.enable
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (void)
   */
  public static final native void Mg$cuhZc(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.findElementType
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param startId (int)
   * @param elementType (java.lang.String)
   * @param forwards (boolean)
   * @return (int)
   */
  public static final native int MavOU0SM(long nativeWebContentsAccessibilityAndroid, Object caller,
      int startId, String elementType, boolean forwards);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.focus
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (void)
   */
  public static final native void MG_OiJKg(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getCharacterBoundingBoxes
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @param start (int)
   * @param len (int)
   * @return (int[])
   */
  public static final native int[] MVBiMGvZ(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id, int start, int len);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getEditableTextSelectionEnd
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (int)
   */
  public static final native int Mxt_kc4Q(long nativeWebContentsAccessibilityAndroid, Object caller,
      int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getEditableTextSelectionStart
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (int)
   */
  public static final native int MnVi6Frs(long nativeWebContentsAccessibilityAndroid, Object caller,
      int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getIdForElementAfterElementHostingAutofillPopup
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (int)
   */
  public static final native int Mk31b3DX(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getRootId
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (int)
   */
  public static final native int MI8pU34f(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getSupportedHtmlElementTypes
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (java.lang.String)
   */
  public static final native String MPyIoFYC(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.getTextLength
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (int)
   */
  public static final native int MhMiVz6m(long nativeWebContentsAccessibilityAndroid, Object caller,
      int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.init
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long MjYAnP1s(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.isAutofillPopupNode
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean M5uHFthk(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.isEditableText
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean MCMbXu4W(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.isEnabled
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (boolean)
   */
  public static final native boolean Mr9fGid2(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.isFocused
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean M8UuMlLD(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.isNodeValid
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean MTBNGzHX(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.isSlider
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean MkaakTGI(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.loadInlineTextBoxes
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (void)
   */
  public static final native void M2WbOJ7$(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.moveAccessibilityFocus
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param oldId (int)
   * @param newId (int)
   * @return (void)
   */
  public static final native void MPQKLw45(long nativeWebContentsAccessibilityAndroid,
      Object caller, int oldId, int newId);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.nextAtGranularity
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param selectionGranularity (int)
   * @param extendSelection (boolean)
   * @param id (int)
   * @param cursorIndex (int)
   * @return (boolean)
   */
  public static final native boolean McKjfBnu(long nativeWebContentsAccessibilityAndroid,
      Object caller, int selectionGranularity, boolean extendSelection, int id, int cursorIndex);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.onAutofillPopupDismissed
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (void)
   */
  public static final native void MdET073e(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.onAutofillPopupDisplayed
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @return (void)
   */
  public static final native void MMiqVowe(long nativeWebContentsAccessibilityAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.populateAccessibilityEvent
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param event (android.view.accessibility.AccessibilityEvent)
   * @param id (int)
   * @param eventType (int)
   * @return (boolean)
   */
  public static final native boolean M2E1dEU9(long nativeWebContentsAccessibilityAndroid,
      Object caller, Object event, int id, int eventType);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.populateAccessibilityNodeInfo
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param info (android.view.accessibility.AccessibilityNodeInfo)
   * @param id (int)
   * @return (boolean)
   */
  public static final native boolean MJGtghd9(long nativeWebContentsAccessibilityAndroid,
      Object caller, Object info, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.previousAtGranularity
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param selectionGranularity (int)
   * @param extendSelection (boolean)
   * @param id (int)
   * @param cursorIndex (int)
   * @return (boolean)
   */
  public static final native boolean M3suD0ji(long nativeWebContentsAccessibilityAndroid,
      Object caller, int selectionGranularity, boolean extendSelection, int id, int cursorIndex);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.scroll
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @param direction (int)
   * @return (boolean)
   */
  public static final native boolean MNch0m9c(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id, int direction);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.scrollToMakeNodeVisible
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (void)
   */
  public static final native void MB302_MP(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.setSelection
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @param start (int)
   * @param end (int)
   * @return (void)
   */
  public static final native void MVuu0R4P(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id, int start, int end);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.setTextFieldValue
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @param newValue (java.lang.String)
   * @return (void)
   */
  public static final native void MEJD7Boi(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id, String newValue);

  /**
   * org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl.showContextMenu
   * @param nativeWebContentsAccessibilityAndroid (long)
   * @param caller (org.chromium.content.browser.accessibility.WebContentsAccessibilityImpl)
   * @param id (int)
   * @return (void)
   */
  public static final native void MOikWIf9(long nativeWebContentsAccessibilityAndroid,
      Object caller, int id);

  /**
   * org.chromium.content.browser.accessibility.captioning.CaptioningController.init
   * @param caller (org.chromium.content.browser.accessibility.captioning.CaptioningController)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long MX95jWaj(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.accessibility.captioning.CaptioningController.setTextTrackSettings
   * @param nativeCaptioningController (long)
   * @param caller (org.chromium.content.browser.accessibility.captioning.CaptioningController)
   * @param textTracksEnabled (boolean)
   * @param textTrackBackgroundColor (java.lang.String)
   * @param textTrackFontFamily (java.lang.String)
   * @param textTrackFontStyle (java.lang.String)
   * @param textTrackFontVariant (java.lang.String)
   * @param textTrackTextColor (java.lang.String)
   * @param textTrackTextShadow (java.lang.String)
   * @param textTrackTextSize (java.lang.String)
   * @return (void)
   */
  public static final native void MM3_AH7F(long nativeCaptioningController, Object caller,
      boolean textTracksEnabled, String textTrackBackgroundColor, String textTrackFontFamily,
      String textTrackFontStyle, String textTrackFontVariant, String textTrackTextColor,
      String textTrackTextShadow, String textTrackTextSize);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.completeInit
   * @param nativeDialogOverlayImpl (long)
   * @param caller (org.chromium.content.browser.androidoverlay.DialogOverlayImpl)
   * @return (void)
   */
  public static final native void MQAm7B7f(long nativeDialogOverlayImpl, Object caller);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.destroy
   * @param nativeDialogOverlayImpl (long)
   * @param caller (org.chromium.content.browser.androidoverlay.DialogOverlayImpl)
   * @return (void)
   */
  public static final native void MJj9v_ba(long nativeDialogOverlayImpl, Object caller);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.getCompositorOffset
   * @param nativeDialogOverlayImpl (long)
   * @param caller (org.chromium.content.browser.androidoverlay.DialogOverlayImpl)
   * @param rect (org.chromium.gfx.mojom.Rect)
   * @return (void)
   */
  public static final native void MAd6qeVr(long nativeDialogOverlayImpl, Object caller,
      Object rect);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.init
   * @param caller (org.chromium.content.browser.androidoverlay.DialogOverlayImpl)
   * @param high (long)
   * @param low (long)
   * @param isPowerEfficient (boolean)
   * @return (long)
   */
  public static final native long MqPi0d6D(Object caller, long high, long low,
      boolean isPowerEfficient);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.lookupSurfaceForTesting
   * @param surfaceId (int)
   * @return (android.view.Surface)
   */
  public static final native Object MzUgOpRk(int surfaceId);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.registerSurface
   * @param surface (android.view.Surface)
   * @return (int)
   */
  public static final native int MpcpmTlm(Object surface);

  /**
   * org.chromium.content.browser.androidoverlay.DialogOverlayImpl.unregisterSurface
   * @param surfaceId (int)
   * @return (void)
   */
  public static final native void M1e4GdYZ(int surfaceId);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.canGoBack
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (boolean)
   */
  public static final native boolean MgAw5sIR(long nativeNavigationControllerAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.canGoForward
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (boolean)
   */
  public static final native boolean MCUxt83x(long nativeNavigationControllerAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.canGoToOffset
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param offset (int)
   * @return (boolean)
   */
  public static final native boolean M4jjW0jG(long nativeNavigationControllerAndroid, Object caller,
      int offset);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.cancelPendingReload
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void MNF4lMMb(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.clearHistory
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void MK2ttcH1(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.clearSslPreferences
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void MpKIKzer(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.continuePendingReload
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void Mp5SLq_N(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getDirectedNavigationHistory
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param history (org.chromium.content_public.browser.NavigationHistory)
   * @param isForward (boolean)
   * @param itemLimit (int)
   * @return (void)
   */
  public static final native void Mx5VuK3_(long nativeNavigationControllerAndroid, Object caller,
      Object history, boolean isForward, int itemLimit);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getEntryAtIndex
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param index (int)
   * @return (org.chromium.content_public.browser.NavigationEntry)
   */
  public static final native Object MLcS2$Fy(long nativeNavigationControllerAndroid, Object caller,
      int index);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getEntryExtraData
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param index (int)
   * @param key (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String McQE1GI8(long nativeNavigationControllerAndroid, Object caller,
      int index, String key);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getLastCommittedEntryIndex
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (int)
   */
  public static final native int Mil0WqAo(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getNavigationHistory
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param history (java.lang.Object)
   * @return (int)
   */
  public static final native int MUZRDUOx(long nativeNavigationControllerAndroid, Object caller,
      Object history);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getPendingEntry
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (org.chromium.content_public.browser.NavigationEntry)
   */
  public static final native Object Mgxh2WfC(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getUseDesktopUserAgent
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (boolean)
   */
  public static final native boolean MCIN9$qH(long nativeNavigationControllerAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.getVisibleEntry
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (org.chromium.content_public.browser.NavigationEntry)
   */
  public static final native Object MHqMy8sY(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.goBack
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void Mdhd0AR3(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.goForward
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void MEEEhNfT(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.goToNavigationIndex
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param index (int)
   * @return (void)
   */
  public static final native void MuxwAbEo(long nativeNavigationControllerAndroid, Object caller,
      int index);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.goToOffset
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param offset (int)
   * @return (void)
   */
  public static final native void ML_uBbdi(long nativeNavigationControllerAndroid, Object caller,
      int offset);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.isEntryMarkedToBeSkipped
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param index (int)
   * @return (boolean)
   */
  public static final native boolean MVjP87pN(long nativeNavigationControllerAndroid, Object caller,
      int index);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.isInitialNavigation
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (boolean)
   */
  public static final native boolean MEOFE6aD(long nativeNavigationControllerAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.loadIfNecessary
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void MWJb9aa$(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.loadUrl
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param url (java.lang.String)
   * @param loadUrlType (int)
   * @param transitionType (int)
   * @param referrerUrl (java.lang.String)
   * @param referrerPolicy (int)
   * @param uaOverrideOption (int)
   * @param extraHeaders (java.lang.String)
   * @param postData (org.chromium.content_public.common.ResourceRequestBody)
   * @param baseUrlForDataUrl (java.lang.String)
   * @param virtualUrlForDataUrl (java.lang.String)
   * @param dataUrlAsString (java.lang.String)
   * @param canLoadLocalResources (boolean)
   * @param isRendererInitiated (boolean)
   * @param shouldReplaceCurrentEntry (boolean)
   * @return (void)
   */
  public static final native void MAqmDh4t(long nativeNavigationControllerAndroid, Object caller,
      String url, int loadUrlType, int transitionType, String referrerUrl, int referrerPolicy,
      int uaOverrideOption, String extraHeaders, Object postData, String baseUrlForDataUrl,
      String virtualUrlForDataUrl, String dataUrlAsString, boolean canLoadLocalResources,
      boolean isRendererInitiated, boolean shouldReplaceCurrentEntry);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.needsReload
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (boolean)
   */
  public static final native boolean MsUTH_HQ(long nativeNavigationControllerAndroid,
      Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.pruneForwardEntries
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void M2mQucXv(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.reload
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param checkForRepost (boolean)
   * @return (void)
   */
  public static final native void M81h$w2r(long nativeNavigationControllerAndroid, Object caller,
      boolean checkForRepost);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.reloadBypassingCache
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param checkForRepost (boolean)
   * @return (void)
   */
  public static final native void My0bMgld(long nativeNavigationControllerAndroid, Object caller,
      boolean checkForRepost);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.removeEntryAtIndex
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param index (int)
   * @return (boolean)
   */
  public static final native boolean MVbDeBRx(long nativeNavigationControllerAndroid, Object caller,
      int index);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.setEntryExtraData
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param index (int)
   * @param key (java.lang.String)
   * @param value (java.lang.String)
   * @return (void)
   */
  public static final native void Mw19wBW8(long nativeNavigationControllerAndroid, Object caller,
      int index, String key, String value);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.setNeedsReload
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @return (void)
   */
  public static final native void MQgIP2q9(long nativeNavigationControllerAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.NavigationControllerImpl.setUseDesktopUserAgent
   * @param nativeNavigationControllerAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.NavigationControllerImpl)
   * @param override (boolean)
   * @param reloadOnChange (boolean)
   * @return (void)
   */
  public static final native void MrilyCK6(long nativeNavigationControllerAndroid, Object caller,
      boolean override, boolean reloadOnChange);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.getAndroidOverlayRoutingToken
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (org.chromium.base.UnguessableToken)
   */
  public static final native Object MJDViTxW(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.getCanonicalUrlForSharing
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @param callback (org.chromium.base.Callback<java.lang.String>)
   * @return (void)
   */
  public static final native void MUV0o0vB(long nativeRenderFrameHostAndroid, Object caller,
      Object callback);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.getLastCommittedOrigin
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (org.chromium.url.Origin)
   */
  public static final native Object Mcdslkop(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.getLastCommittedURL
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (java.lang.String)
   */
  public static final native String MBg$jIAu(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.isPaymentFeaturePolicyEnabled
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (boolean)
   */
  public static final native boolean MfPH28_F(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.isProcessBlocked
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (boolean)
   */
  public static final native boolean M6cbowZq(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.isRenderFrameCreated
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (boolean)
   */
  public static final native boolean MhaRMzRy(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.framehost.RenderFrameHostImpl.notifyUserActivation
   * @param nativeRenderFrameHostAndroid (long)
   * @param caller (org.chromium.content.browser.framehost.RenderFrameHostImpl)
   * @return (void)
   */
  public static final native void M$j92GA1(long nativeRenderFrameHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.input.DateTimeChooserAndroid.cancelDialog
   * @param nativeDateTimeChooserAndroid (long)
   * @param caller (org.chromium.content.browser.input.DateTimeChooserAndroid)
   * @return (void)
   */
  public static final native void MCtaZNwj(long nativeDateTimeChooserAndroid, Object caller);

  /**
   * org.chromium.content.browser.input.DateTimeChooserAndroid.replaceDateTime
   * @param nativeDateTimeChooserAndroid (long)
   * @param caller (org.chromium.content.browser.input.DateTimeChooserAndroid)
   * @param dialogValue (double)
   * @return (void)
   */
  public static final native void MgUhdCLo(long nativeDateTimeChooserAndroid, Object caller,
      double dialogValue);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.advanceFocusInForm
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param focusType (int)
   * @return (void)
   */
  public static final native void Mm_z91JF(long nativeImeAdapterAndroid, Object caller,
      int focusType);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.appendBackgroundColorSpan
   * @param spanPtr (long)
   * @param start (int)
   * @param end (int)
   * @param backgroundColor (int)
   * @return (void)
   */
  public static final native void MqqhDONa(long spanPtr, int start, int end, int backgroundColor);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.appendSuggestionSpan
   * @param spanPtr (long)
   * @param start (int)
   * @param end (int)
   * @param isMisspelling (boolean)
   * @param removeOnFinishComposing (boolean)
   * @param underlineColor (int)
   * @param suggestionHighlightColor (int)
   * @param suggestions (java.lang.String[])
   * @return (void)
   */
  public static final native void M$b45Vvn(long spanPtr, int start, int end, boolean isMisspelling,
      boolean removeOnFinishComposing, int underlineColor, int suggestionHighlightColor,
      String[] suggestions);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.appendUnderlineSpan
   * @param spanPtr (long)
   * @param start (int)
   * @param end (int)
   * @return (void)
   */
  public static final native void MFfRzF$Z(long spanPtr, int start, int end);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.commitText
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param text (java.lang.CharSequence)
   * @param textStr (java.lang.String)
   * @param newCursorPosition (int)
   * @return (void)
   */
  public static final native void Mb6t43di(long nativeImeAdapterAndroid, Object caller, Object text,
      String textStr, int newCursorPosition);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.deleteSurroundingText
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param before (int)
   * @param after (int)
   * @return (void)
   */
  public static final native void M26GCjn5(long nativeImeAdapterAndroid, Object caller, int before,
      int after);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.deleteSurroundingTextInCodePoints
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param before (int)
   * @param after (int)
   * @return (void)
   */
  public static final native void Mvb046o_(long nativeImeAdapterAndroid, Object caller, int before,
      int after);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.finishComposingText
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @return (void)
   */
  public static final native void M_V5g5ie(long nativeImeAdapterAndroid, Object caller);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.init
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long MhbsQh1H(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.requestCursorUpdate
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param immediateRequest (boolean)
   * @param monitorRequest (boolean)
   * @return (void)
   */
  public static final native void MdwW1P2L(long nativeImeAdapterAndroid, Object caller,
      boolean immediateRequest, boolean monitorRequest);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.requestTextInputStateUpdate
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @return (boolean)
   */
  public static final native boolean M7o5Xhhi(long nativeImeAdapterAndroid, Object caller);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.sendKeyEvent
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param event (android.view.KeyEvent)
   * @param type (int)
   * @param modifiers (int)
   * @param timestampMs (long)
   * @param keyCode (int)
   * @param scanCode (int)
   * @param isSystemKey (boolean)
   * @param unicodeChar (int)
   * @return (boolean)
   */
  public static final native boolean M1qwlrOP(long nativeImeAdapterAndroid, Object caller,
      Object event, int type, int modifiers, long timestampMs, int keyCode, int scanCode,
      boolean isSystemKey, int unicodeChar);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.setComposingRegion
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param start (int)
   * @param end (int)
   * @return (void)
   */
  public static final native void M8ty0WHb(long nativeImeAdapterAndroid, Object caller, int start,
      int end);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.setComposingText
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param text (java.lang.CharSequence)
   * @param textStr (java.lang.String)
   * @param newCursorPosition (int)
   * @return (void)
   */
  public static final native void Mlslst_P(long nativeImeAdapterAndroid, Object caller, Object text,
      String textStr, int newCursorPosition);

  /**
   * org.chromium.content.browser.input.ImeAdapterImpl.setEditableSelectionOffsets
   * @param nativeImeAdapterAndroid (long)
   * @param caller (org.chromium.content.browser.input.ImeAdapterImpl)
   * @param start (int)
   * @param end (int)
   * @return (void)
   */
  public static final native void MmtjCblb(long nativeImeAdapterAndroid, Object caller, int start,
      int end);

  /**
   * org.chromium.content.browser.input.SelectPopup.selectMenuItems
   * @param nativeSelectPopup (long)
   * @param caller (org.chromium.content.browser.input.SelectPopup)
   * @param nativeSelectPopupSourceFrame (long)
   * @param indices (int[])
   * @return (void)
   */
  public static final native void ME0LgXse(long nativeSelectPopup, Object caller,
      long nativeSelectPopupSourceFrame, int[] indices);

  /**
   * org.chromium.content.browser.input.TextSuggestionHost.applySpellCheckSuggestion
   * @param nativeTextSuggestionHostAndroid (long)
   * @param caller (org.chromium.content.browser.input.TextSuggestionHost)
   * @param suggestion (java.lang.String)
   * @return (void)
   */
  public static final native void M7RnYR2r(long nativeTextSuggestionHostAndroid, Object caller,
      String suggestion);

  /**
   * org.chromium.content.browser.input.TextSuggestionHost.applyTextSuggestion
   * @param nativeTextSuggestionHostAndroid (long)
   * @param caller (org.chromium.content.browser.input.TextSuggestionHost)
   * @param markerTag (int)
   * @param suggestionIndex (int)
   * @return (void)
   */
  public static final native void MIADbBhq(long nativeTextSuggestionHostAndroid, Object caller,
      int markerTag, int suggestionIndex);

  /**
   * org.chromium.content.browser.input.TextSuggestionHost.deleteActiveSuggestionRange
   * @param nativeTextSuggestionHostAndroid (long)
   * @param caller (org.chromium.content.browser.input.TextSuggestionHost)
   * @return (void)
   */
  public static final native void MCBTtv2g(long nativeTextSuggestionHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.input.TextSuggestionHost.onNewWordAddedToDictionary
   * @param nativeTextSuggestionHostAndroid (long)
   * @param caller (org.chromium.content.browser.input.TextSuggestionHost)
   * @param word (java.lang.String)
   * @return (void)
   */
  public static final native void MpJ8AQhr(long nativeTextSuggestionHostAndroid, Object caller,
      String word);

  /**
   * org.chromium.content.browser.input.TextSuggestionHost.onSuggestionMenuClosed
   * @param nativeTextSuggestionHostAndroid (long)
   * @param caller (org.chromium.content.browser.input.TextSuggestionHost)
   * @return (void)
   */
  public static final native void MnvYa0QF(long nativeTextSuggestionHostAndroid, Object caller);

  /**
   * org.chromium.content.browser.selection.SelectionPopupControllerImpl.init
   * @param caller (org.chromium.content.browser.selection.SelectionPopupControllerImpl)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long MJHXNa8U(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.selection.SelectionPopupControllerImpl.setTextHandlesTemporarilyHidden
   * @param nativeSelectionPopupController (long)
   * @param caller (org.chromium.content.browser.selection.SelectionPopupControllerImpl)
   * @param hidden (boolean)
   * @return (void)
   */
  public static final native void M01adZlM(long nativeSelectionPopupController, Object caller,
      boolean hidden);

  /**
   * org.chromium.content.browser.selection.SmartSelectionClient.cancelAllRequests
   * @param nativeSmartSelectionClient (long)
   * @param caller (org.chromium.content.browser.selection.SmartSelectionClient)
   * @return (void)
   */
  public static final native void MVHq2mA2(long nativeSmartSelectionClient, Object caller);

  /**
   * org.chromium.content.browser.selection.SmartSelectionClient.init
   * @param caller (org.chromium.content.browser.selection.SmartSelectionClient)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long MFA_dMJC(Object caller, Object webContents);

  /**
   * org.chromium.content.browser.selection.SmartSelectionClient.requestSurroundingText
   * @param nativeSmartSelectionClient (long)
   * @param caller (org.chromium.content.browser.selection.SmartSelectionClient)
   * @param numExtraCharacters (int)
   * @param callbackData (int)
   * @return (void)
   */
  public static final native void M2GZ6ZNR(long nativeSmartSelectionClient, Object caller,
      int numExtraCharacters, int callbackData);

  /**
   * org.chromium.content.browser.sms.SmsReceiver.onReceive
   * @param nativeSmsProviderAndroid (long)
   * @param sms (java.lang.String)
   * @return (void)
   */
  public static final native void McAbc1cO(long nativeSmsProviderAndroid, String sms);

  /**
   * org.chromium.content.browser.sms.SmsReceiver.onTimeout
   * @param nativeSmsProviderAndroid (long)
   * @return (void)
   */
  public static final native void MW3td7Xy(long nativeSmsProviderAndroid);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.addMessageToDevToolsConsole
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param level (int)
   * @param message (java.lang.String)
   * @return (void)
   */
  public static final native void MseJ7A4a(long nativeWebContentsAndroid, Object caller, int level,
      String message);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.adjustSelectionByCharacterOffset
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param startAdjust (int)
   * @param endAdjust (int)
   * @param showSelectionMenu (boolean)
   * @return (void)
   */
  public static final native void MjgOFo_o(long nativeWebContentsAndroid, Object caller,
      int startAdjust, int endAdjust, boolean showSelectionMenu);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.clearNativeReference
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void M0iG1Oc2(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.collapseSelection
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MDK_KK0z(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.copy
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MpfMxfut(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.cut
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MhIiCaN7(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.destroyWebContents
   * @param webContentsAndroidPtr (long)
   * @return (void)
   */
  public static final native void MxxzO9Pe(long webContentsAndroidPtr);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.downloadImage
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param url (java.lang.String)
   * @param isFavicon (boolean)
   * @param maxBitmapSize (int)
   * @param bypassCache (boolean)
   * @param callback (org.chromium.content_public.browser.ImageDownloadCallback)
   * @return (int)
   */
  public static final native int Mi3V1mlO(long nativeWebContentsAndroid, Object caller, String url,
      boolean isFavicon, int maxBitmapSize, boolean bypassCache, Object callback);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.evaluateJavaScript
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param script (java.lang.String)
   * @param callback (org.chromium.content_public.browser.JavaScriptCallback)
   * @return (void)
   */
  public static final native void M0uS2SDH(long nativeWebContentsAndroid, Object caller,
      String script, Object callback);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.evaluateJavaScriptForTests
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param script (java.lang.String)
   * @param callback (org.chromium.content_public.browser.JavaScriptCallback)
   * @return (void)
   */
  public static final native void MPoHZQTR(long nativeWebContentsAndroid, Object caller,
      String script, Object callback);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.exitFullscreen
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void M6c69Eq5(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.focusLocationBarByDefault
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean MkIL2bW9(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.fromNativePtr
   * @param webContentsAndroidPtr (long)
   * @return (org.chromium.content_public.browser.WebContents)
   */
  public static final native Object M$eaBDjM(long webContentsAndroidPtr);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getEncoding
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (java.lang.String)
   */
  public static final native String M4pZ82rG(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getFocusedFrame
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (org.chromium.content_public.browser.RenderFrameHost)
   */
  public static final native Object MT2cFaRc(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getFullscreenVideoSize
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (android.graphics.Rect)
   */
  public static final native Object MN9JdEk5(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getHeight
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (int)
   */
  public static final native int MRVeP4Wk(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getInnerWebContents
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (org.chromium.content.browser.webcontents.WebContentsImpl[])
   */
  public static final native Object[] MJSe_z5C(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getLastCommittedURL
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (java.lang.String)
   */
  public static final native String MrqMRJsG(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getLoadProgress
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (float)
   */
  public static final native float MoQgY_pw(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getMainFrame
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (org.chromium.content_public.browser.RenderFrameHost)
   */
  public static final native Object MjidYpBx(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getOrCreateEventForwarder
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (org.chromium.ui.base.EventForwarder)
   */
  public static final native Object MJJFrmZs(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getRenderWidgetHostView
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (org.chromium.content.browser.RenderWidgetHostViewImpl)
   */
  public static final native Object Mj9slq6o(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getThemeColor
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (int)
   */
  public static final native int MGZCJ6jO(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getTitle
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (java.lang.String)
   */
  public static final native String M7OgjMU8(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getTopLevelNativeWindow
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (org.chromium.ui.base.WindowAndroid)
   */
  public static final native Object MunY3e38(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getVisibleURL
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (java.lang.String)
   */
  public static final native String M8927Uaf(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.getWidth
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (int)
   */
  public static final native int MB0i5_ri(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.hasAccessedInitialDocument
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean M6It8dra(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.hasActiveEffectivelyFullscreenVideo
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean MZao1OQG(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.isBeingDestroyed
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean M5A4vDoy(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.isIncognito
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean MZbfAARG(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.isLoading
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean MtSTkEp2(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.isLoadingToDifferentDocument
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean M93b11tE(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.isPictureInPictureAllowedForFullscreenVideo
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean MS0xMYL9(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.isShowingInterstitialPage
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (boolean)
   */
  public static final native boolean MPePqASo(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.notifyBrowserControlsHeightChanged
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MgcGzQax(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.notifyRendererPreferenceUpdate
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void Mzsx8Sk2(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.onHide
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MHNkuuGQ(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.onScaleFactorChanged
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MqhGkzSt(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.onShow
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MtakfqIH(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.paste
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MYRJ_nNk(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.pasteAsPlainText
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MdSkKRWg(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.postMessageToMainFrame
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param message (java.lang.String)
   * @param sourceOrigin (java.lang.String)
   * @param targetOrigin (java.lang.String)
   * @param ports (org.chromium.content_public.browser.MessagePort[])
   * @return (void)
   */
  public static final native void MZFXk0el(long nativeWebContentsAndroid, Object caller,
      String message, String sourceOrigin, String targetOrigin, Object[] ports);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.replace
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param word (java.lang.String)
   * @return (void)
   */
  public static final native void MevqfbP8(long nativeWebContentsAndroid, Object caller,
      String word);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.requestAccessibilitySnapshot
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param callback (org.chromium.content_public.browser.AccessibilitySnapshotCallback)
   * @return (void)
   */
  public static final native void M16eLpU9(long nativeWebContentsAndroid, Object caller,
      Object callback);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.requestSmartClipExtract
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param callback (org.chromium.content.browser.webcontents.WebContentsImpl.SmartClipCallback)
   * @param x (int)
   * @param y (int)
   * @param width (int)
   * @param height (int)
   * @return (void)
   */
  public static final native void MHF1rPTW(long nativeWebContentsAndroid, Object caller,
      Object callback, int x, int y, int width, int height);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.resumeLoadingCreatedWebContents
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MQnLkNkP(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.scrollFocusedEditableNodeIntoView
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MgbVQff0(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.selectAll
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MNvj1u1S(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.selectWordAroundCaret
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MlfwWHGJ(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.sendOrientationChangeEvent
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param orientation (int)
   * @return (void)
   */
  public static final native void MlztHl3v(long nativeWebContentsAndroid, Object caller,
      int orientation);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setAudioMuted
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param mute (boolean)
   * @return (void)
   */
  public static final native void M4fkbrQM(long nativeWebContentsAndroid, Object caller,
      boolean mute);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setDisplayCutoutSafeArea
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param top (int)
   * @param left (int)
   * @param bottom (int)
   * @param right (int)
   * @return (void)
   */
  public static final native void MtjP03pj(long nativeWebContentsAndroid, Object caller, int top,
      int left, int bottom, int right);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setFocus
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param focused (boolean)
   * @return (void)
   */
  public static final native void M9QxNoTJ(long nativeWebContentsAndroid, Object caller,
      boolean focused);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setHasPersistentVideo
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param value (boolean)
   * @return (void)
   */
  public static final native void M12SiBFk(long nativeWebContentsAndroid, Object caller,
      boolean value);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setImportance
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param importance (int)
   * @return (void)
   */
  public static final native void MkBVGSRs(long nativeWebContentsAndroid, Object caller,
      int importance);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setOverscrollRefreshHandler
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param nativeOverscrollRefreshHandler (org.chromium.ui.OverscrollRefreshHandler)
   * @return (void)
   */
  public static final native void MTTB8znA(long nativeWebContentsAndroid, Object caller,
      Object nativeOverscrollRefreshHandler);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setSize
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param width (int)
   * @param height (int)
   * @return (void)
   */
  public static final native void M7tTrJ_X(long nativeWebContentsAndroid, Object caller, int width,
      int height);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setSpatialNavigationDisabled
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param disabled (boolean)
   * @return (void)
   */
  public static final native void MjBPqNgx(long nativeWebContentsAndroid, Object caller,
      boolean disabled);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setTopLevelNativeWindow
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param windowAndroid (org.chromium.ui.base.WindowAndroid)
   * @return (void)
   */
  public static final native void MOKG_Wbb(long nativeWebContentsAndroid, Object caller,
      Object windowAndroid);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.setViewAndroidDelegate
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @param viewDelegate (org.chromium.ui.base.ViewAndroidDelegate)
   * @return (void)
   */
  public static final native void MgyWdCWB(long nativeWebContentsAndroid, Object caller,
      Object viewDelegate);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.stop
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void M$$25N5$(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsImpl.suspendAllMediaPlayers
   * @param nativeWebContentsAndroid (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (void)
   */
  public static final native void MSOsA4Ii(long nativeWebContentsAndroid, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsObserverProxy.destroy
   * @param nativeWebContentsObserverProxy (long)
   * @param caller (org.chromium.content.browser.webcontents.WebContentsObserverProxy)
   * @return (void)
   */
  public static final native void M7giG0Ri(long nativeWebContentsObserverProxy, Object caller);

  /**
   * org.chromium.content.browser.webcontents.WebContentsObserverProxy.init
   * @param caller (org.chromium.content.browser.webcontents.WebContentsObserverProxy)
   * @param webContents (org.chromium.content.browser.webcontents.WebContentsImpl)
   * @return (long)
   */
  public static final native long MTpUzW91(Object caller, Object webContents);

  /**
   * org.chromium.content.common.ServiceManagerConnectionImpl.getConnectorMessagePipeHandle
   * @return (int)
   */
  public static final native int M6vzcDUp();

  /**
   * org.chromium.content_public.browser.LoadUrlParams.isDataScheme
   * @param url (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MWH2gOYe(String url);

  /**
   * org.chromium.content_public.browser.NavigationHandle.removeRequestHeader
   * @param nativeNavigationHandleProxy (long)
   * @param headerName (java.lang.String)
   * @return (void)
   */
  public static final native void Mo7byNs$(long nativeNavigationHandleProxy, String headerName);

  /**
   * org.chromium.content_public.browser.NavigationHandle.setRequestHeader
   * @param nativeNavigationHandleProxy (long)
   * @param headerName (java.lang.String)
   * @param headerValue (java.lang.String)
   * @return (void)
   */
  public static final native void MACALLtV(long nativeNavigationHandleProxy, String headerName,
      String headerValue);

  /**
   * org.chromium.content_public.common.ResourceRequestBody.createResourceRequestBodyFromBytes
   * @param httpBody (byte[])
   * @return (byte[])
   */
  public static final native byte[] MugoAW_d(byte[] httpBody);

  /**
   * org.chromium.content_public.common.UseZoomForDSFPolicy.isUseZoomForDSFEnabled
   * @return (boolean)
   */
  public static final native boolean MbmAQ8fm();
}
