package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.android_webview.AndroidProtocolHandler.getAndroidAssetPath
   * @return (java.lang.String)
   */
  public static final native String Myi_XSsy();

  /**
   * org.chromium.android_webview.AndroidProtocolHandler.getAndroidResourcePath
   * @return (java.lang.String)
   */
  public static final native String MZEbjzws();

  /**
   * org.chromium.android_webview.AwAutofillClient.dismissed
   * @param nativeAwAutofillClient (long)
   * @param caller (org.chromium.android_webview.AwAutofillClient)
   * @return (void)
   */
  public static final native void M2z_jbiy(long nativeAwAutofillClient, Object caller);

  /**
   * org.chromium.android_webview.AwAutofillClient.suggestionSelected
   * @param nativeAwAutofillClient (long)
   * @param caller (org.chromium.android_webview.AwAutofillClient)
   * @param position (int)
   * @return (void)
   */
  public static final native void Mg2XGOMM(long nativeAwAutofillClient, Object caller,
      int position);

  /**
   * org.chromium.android_webview.AwBrowserContext.getDefaultJava
   * @return (org.chromium.android_webview.AwBrowserContext)
   */
  public static final native Object MCLx2xtg();

  /**
   * org.chromium.android_webview.AwBrowserContext.getQuotaManagerBridge
   * @param nativeAwBrowserContext (long)
   * @return (long)
   */
  public static final native long MyGX0Tx3(long nativeAwBrowserContext);

  /**
   * org.chromium.android_webview.AwContents.addVisitedLinks
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param visitedLinks (java.lang.String[])
   * @return (void)
   */
  public static final native void MGEWt61o(long nativeAwContents, Object caller,
      String[] visitedLinks);

  /**
   * org.chromium.android_webview.AwContents.addWebMessageListener
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param listener (org.chromium.android_webview.WebMessageListenerHolder)
   * @param jsObjectName (java.lang.String)
   * @param allowedOrigins (java.lang.String[])
   * @return (java.lang.String)
   */
  public static final native String MxPw2eDG(long nativeAwContents, Object caller, Object listener,
      String jsObjectName, String[] allowedOrigins);

  /**
   * org.chromium.android_webview.AwContents.capturePicture
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param width (int)
   * @param height (int)
   * @return (long)
   */
  public static final native long MpPu_UgV(long nativeAwContents, Object caller, int width,
      int height);

  /**
   * org.chromium.android_webview.AwContents.clearCache
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param includeDiskFiles (boolean)
   * @return (void)
   */
  public static final native void MhT$Vsgm(long nativeAwContents, Object caller,
      boolean includeDiskFiles);

  /**
   * org.chromium.android_webview.AwContents.clearMatches
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MFtcGkhm(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.clearView
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MsURZ4Xi(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.createPdfExporter
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param awPdfExporter (org.chromium.android_webview.AwPdfExporter)
   * @return (void)
   */
  public static final native void MND9REwd(long nativeAwContents, Object caller,
      Object awPdfExporter);

  /**
   * org.chromium.android_webview.AwContents.destroy
   * @param nativeAwContents (long)
   * @return (void)
   */
  public static final native void MQGusfGb(long nativeAwContents);

  /**
   * org.chromium.android_webview.AwContents.documentHasImages
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param message (android.os.Message)
   * @return (void)
   */
  public static final native void M74pgHWN(long nativeAwContents, Object caller, Object message);

  /**
   * org.chromium.android_webview.AwContents.enableOnNewPicture
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param enabled (boolean)
   * @return (void)
   */
  public static final native void MjvLhcRF(long nativeAwContents, Object caller, boolean enabled);

  /**
   * org.chromium.android_webview.AwContents.evaluateJavaScriptOnInterstitialForTesting
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param script (java.lang.String)
   * @param jsCallback (org.chromium.content_public.browser.JavaScriptCallback)
   * @return (void)
   */
  public static final native void MpysRKyN(long nativeAwContents, Object caller, String script,
      Object jsCallback);

  /**
   * org.chromium.android_webview.AwContents.findAllAsync
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param searchString (java.lang.String)
   * @return (void)
   */
  public static final native void MkkpS1L9(long nativeAwContents, Object caller,
      String searchString);

  /**
   * org.chromium.android_webview.AwContents.findNext
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param forward (boolean)
   * @return (void)
   */
  public static final native void M21lr0OA(long nativeAwContents, Object caller, boolean forward);

  /**
   * org.chromium.android_webview.AwContents.focusFirstNode
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MunvchpP(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.generateMHTML
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param path (java.lang.String)
   * @param callback (org.chromium.base.Callback<java.lang.String>)
   * @return (void)
   */
  public static final native void MfwgZRb_(long nativeAwContents, Object caller, String path,
      Object callback);

  /**
   * org.chromium.android_webview.AwContents.getBrowserContext
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (org.chromium.android_webview.AwBrowserContext)
   */
  public static final native Object Mg88vWvb(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.getCertificate
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (byte[])
   */
  public static final native byte[] MJl6bbdC(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.getEffectivePriority
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (int)
   */
  public static final native int MmkSmonh(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.getNativeInstanceCount
   * @return (int)
   */
  public static final native int MpyFb$bm();

  /**
   * org.chromium.android_webview.AwContents.getOpaqueState
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (byte[])
   */
  public static final native byte[] MtUUIkJC(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.getRenderProcess
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (org.chromium.android_webview.AwRenderProcess)
   */
  public static final native Object Mj2HEglc(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.getSafeBrowsingLocaleForTesting
   * @return (java.lang.String)
   */
  public static final native String M8bzablT();

  /**
   * org.chromium.android_webview.AwContents.getWebContents
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (org.chromium.content_public.browser.WebContents)
   */
  public static final native Object MybAxcKt(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.grantFileSchemeAccesstoChildProcess
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void Mt543z$z(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.hasRequiredHardwareExtensions
   * @return (boolean)
   */
  public static final native boolean MmfcaMzE();

  /**
   * org.chromium.android_webview.AwContents.init
   * @param browserContextPointer (long)
   * @return (long)
   */
  public static final native long MFiR_zHY(long browserContextPointer);

  /**
   * org.chromium.android_webview.AwContents.insertVisualStateCallback
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param requestId (long)
   * @param callback (org.chromium.android_webview.AwContents.VisualStateCallback)
   * @return (void)
   */
  public static final native void ME4bwr8X(long nativeAwContents, Object caller, long requestId,
      Object callback);

  /**
   * org.chromium.android_webview.AwContents.invokeGeolocationCallback
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param value (boolean)
   * @param requestingFrame (java.lang.String)
   * @return (void)
   */
  public static final native void M0cKB_Do(long nativeAwContents, Object caller, boolean value,
      String requestingFrame);

  /**
   * org.chromium.android_webview.AwContents.isDisplayingInterstitialForTesting
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (boolean)
   */
  public static final native boolean MYvj_j$8(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.isVisible
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (boolean)
   */
  public static final native boolean M5$3H1S$(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.killRenderProcess
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void M6HE38c5(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.needToDrawBackgroundColor
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (boolean)
   */
  public static final native boolean Mcwwaem4(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.onAttachedToWindow
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param w (int)
   * @param h (int)
   * @return (void)
   */
  public static final native void MtQhJq6u(long nativeAwContents, Object caller, int w, int h);

  /**
   * org.chromium.android_webview.AwContents.onComputeScroll
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param currentAnimationTimeMillis (long)
   * @return (void)
   */
  public static final native void MkR1ETvU(long nativeAwContents, Object caller,
      long currentAnimationTimeMillis);

  /**
   * org.chromium.android_webview.AwContents.onDetachedFromWindow
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MqVX7tnS(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.onDraw
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param canvas (android.graphics.Canvas)
   * @param isHardwareAccelerated (boolean)
   * @param scrollX (int)
   * @param scrollY (int)
   * @param visibleLeft (int)
   * @param visibleTop (int)
   * @param visibleRight (int)
   * @param visibleBottom (int)
   * @param forceAuxiliaryBitmapRendering (boolean)
   * @return (boolean)
   */
  public static final native boolean MTXp4fn_(long nativeAwContents, Object caller, Object canvas,
      boolean isHardwareAccelerated, int scrollX, int scrollY, int visibleLeft, int visibleTop,
      int visibleRight, int visibleBottom, boolean forceAuxiliaryBitmapRendering);

  /**
   * org.chromium.android_webview.AwContents.onInputEvent
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MQn4UPnT(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.onSizeChanged
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param w (int)
   * @param h (int)
   * @param ow (int)
   * @param oh (int)
   * @return (void)
   */
  public static final native void MNxSIAOu(long nativeAwContents, Object caller, int w, int h,
      int ow, int oh);

  /**
   * org.chromium.android_webview.AwContents.preauthorizePermission
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param origin (java.lang.String)
   * @param resources (long)
   * @return (void)
   */
  public static final native void MZm6NYk2(long nativeAwContents, Object caller, String origin,
      long resources);

  /**
   * org.chromium.android_webview.AwContents.releasePopupAwContents
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (long)
   */
  public static final native long MOttaOmZ(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.removeWebMessageListener
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param jsObjectName (java.lang.String)
   * @return (void)
   */
  public static final native void MJJ_9Fzq(long nativeAwContents, Object caller,
      String jsObjectName);

  /**
   * org.chromium.android_webview.AwContents.requestNewHitTestDataAt
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param x (float)
   * @param y (float)
   * @param touchMajor (float)
   * @return (void)
   */
  public static final native void MbVTYFDu(long nativeAwContents, Object caller, float x, float y,
      float touchMajor);

  /**
   * org.chromium.android_webview.AwContents.restoreFromOpaqueState
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param state (byte[])
   * @return (boolean)
   */
  public static final native boolean M$ugXLRy(long nativeAwContents, Object caller, byte[] state);

  /**
   * org.chromium.android_webview.AwContents.restoreScrollAfterTransition
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param x (int)
   * @param y (int)
   * @return (void)
   */
  public static final native void MFKs48sP(long nativeAwContents, Object caller, int x, int y);

  /**
   * org.chromium.android_webview.AwContents.resumeLoadingCreatedPopupWebContents
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MlAm1rvf(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.scrollTo
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param x (int)
   * @param y (int)
   * @return (void)
   */
  public static final native void Mnc0PDKE(long nativeAwContents, Object caller, int x, int y);

  /**
   * org.chromium.android_webview.AwContents.setAwDrawGLFunctionTable
   * @param functionTablePointer (long)
   * @return (void)
   */
  public static final native void MHELqQxx(long functionTablePointer);

  /**
   * org.chromium.android_webview.AwContents.setAwDrawSWFunctionTable
   * @param functionTablePointer (long)
   * @return (void)
   */
  public static final native void M1aUwTSB(long functionTablePointer);

  /**
   * org.chromium.android_webview.AwContents.setBackgroundColor
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param color (int)
   * @return (void)
   */
  public static final native void MLVoXr_n(long nativeAwContents, Object caller, int color);

  /**
   * org.chromium.android_webview.AwContents.setCompositorFrameConsumer
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param nativeCompositorFrameConsumer (long)
   * @return (void)
   */
  public static final native void MzAVKSgA(long nativeAwContents, Object caller,
      long nativeCompositorFrameConsumer);

  /**
   * org.chromium.android_webview.AwContents.setDipScale
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param dipScale (float)
   * @return (void)
   */
  public static final native void MYYge55A(long nativeAwContents, Object caller, float dipScale);

  /**
   * org.chromium.android_webview.AwContents.setExtraHeadersForUrl
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param url (java.lang.String)
   * @param extraHeaders (java.lang.String)
   * @return (void)
   */
  public static final native void Me4$sHFE(long nativeAwContents, Object caller, String url,
      String extraHeaders);

  /**
   * org.chromium.android_webview.AwContents.setIsPaused
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param paused (boolean)
   * @return (void)
   */
  public static final native void M11ykFVM(long nativeAwContents, Object caller, boolean paused);

  /**
   * org.chromium.android_webview.AwContents.setJavaPeers
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param awContents (org.chromium.android_webview.AwContents)
   * @param webViewWebContentsDelegate (org.chromium.android_webview.AwWebContentsDelegate)
   * @param contentsClientBridge (org.chromium.android_webview.AwContentsClientBridge)
   * @param ioThreadClient (org.chromium.android_webview.AwContentsIoThreadClient)
   * @param navigationInterceptionDelegate (org.chromium.components.navigation_interception.InterceptNavigationDelegate)
   * @param autofillProvider (org.chromium.components.autofill.AutofillProvider)
   * @return (void)
   */
  public static final native void MaOp$2xn(long nativeAwContents, Object caller, Object awContents,
      Object webViewWebContentsDelegate, Object contentsClientBridge, Object ioThreadClient,
      Object navigationInterceptionDelegate, Object autofillProvider);

  /**
   * org.chromium.android_webview.AwContents.setJsOnlineProperty
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param networkUp (boolean)
   * @return (void)
   */
  public static final native void MSO7DbfT(long nativeAwContents, Object caller, boolean networkUp);

  /**
   * org.chromium.android_webview.AwContents.setShouldDownloadFavicons
   * @return (void)
   */
  public static final native void Mbm7UXr0();

  /**
   * org.chromium.android_webview.AwContents.setViewVisibility
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param visible (boolean)
   * @return (void)
   */
  public static final native void MJqblGS2(long nativeAwContents, Object caller, boolean visible);

  /**
   * org.chromium.android_webview.AwContents.setWindowVisibility
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param visible (boolean)
   * @return (void)
   */
  public static final native void MkfSbdDV(long nativeAwContents, Object caller, boolean visible);

  /**
   * org.chromium.android_webview.AwContents.smoothScroll
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param targetX (int)
   * @param targetY (int)
   * @param durationMs (long)
   * @return (void)
   */
  public static final native void MgUWjwjs(long nativeAwContents, Object caller, int targetX,
      int targetY, long durationMs);

  /**
   * org.chromium.android_webview.AwContents.trimMemory
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param level (int)
   * @param visible (boolean)
   * @return (void)
   */
  public static final native void MxV2T4AB(long nativeAwContents, Object caller, int level,
      boolean visible);

  /**
   * org.chromium.android_webview.AwContents.updateDefaultLocale
   * @param locale (java.lang.String)
   * @param localeList (java.lang.String)
   * @return (void)
   */
  public static final native void Mer1B1Jd(String locale, String localeList);

  /**
   * org.chromium.android_webview.AwContents.updateLastHitTestData
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @return (void)
   */
  public static final native void MHBuiDmd(long nativeAwContents, Object caller);

  /**
   * org.chromium.android_webview.AwContents.zoomBy
   * @param nativeAwContents (long)
   * @param caller (org.chromium.android_webview.AwContents)
   * @param delta (float)
   * @return (void)
   */
  public static final native void MuRWIe$h(long nativeAwContents, Object caller, float delta);

  /**
   * org.chromium.android_webview.AwContentsClientBridge.cancelJsResult
   * @param nativeAwContentsClientBridge (long)
   * @param caller (org.chromium.android_webview.AwContentsClientBridge)
   * @param id (int)
   * @return (void)
   */
  public static final native void MXWyhv9x(long nativeAwContentsClientBridge, Object caller,
      int id);

  /**
   * org.chromium.android_webview.AwContentsClientBridge.confirmJsResult
   * @param nativeAwContentsClientBridge (long)
   * @param caller (org.chromium.android_webview.AwContentsClientBridge)
   * @param id (int)
   * @param prompt (java.lang.String)
   * @return (void)
   */
  public static final native void MNISBPG1(long nativeAwContentsClientBridge, Object caller, int id,
      String prompt);

  /**
   * org.chromium.android_webview.AwContentsClientBridge.proceedSslError
   * @param nativeAwContentsClientBridge (long)
   * @param caller (org.chromium.android_webview.AwContentsClientBridge)
   * @param proceed (boolean)
   * @param id (int)
   * @return (void)
   */
  public static final native void MgWlsTs7(long nativeAwContentsClientBridge, Object caller,
      boolean proceed, int id);

  /**
   * org.chromium.android_webview.AwContentsClientBridge.provideClientCertificateResponse
   * @param nativeAwContentsClientBridge (long)
   * @param caller (org.chromium.android_webview.AwContentsClientBridge)
   * @param id (int)
   * @param certChain (byte[][])
   * @param androidKey (java.security.PrivateKey)
   * @return (void)
   */
  public static final native void MZT_Y79r(long nativeAwContentsClientBridge, Object caller, int id,
      byte[][] certChain, Object androidKey);

  /**
   * org.chromium.android_webview.AwContentsClientBridge.takeSafeBrowsingAction
   * @param nativeAwContentsClientBridge (long)
   * @param caller (org.chromium.android_webview.AwContentsClientBridge)
   * @param action (int)
   * @param reporting (boolean)
   * @param requestId (int)
   * @return (void)
   */
  public static final native void MXMPzQYm(long nativeAwContentsClientBridge, Object caller,
      int action, boolean reporting, int requestId);

  /**
   * org.chromium.android_webview.AwContentsStatics.clearClientCertPreferences
   * @param callback (java.lang.Runnable)
   * @return (void)
   */
  public static final native void Ml71D$Ud(Object callback);

  /**
   * org.chromium.android_webview.AwContentsStatics.getProductVersion
   * @return (java.lang.String)
   */
  public static final native String MhBmyxCD();

  /**
   * org.chromium.android_webview.AwContentsStatics.getSafeBrowsingPrivacyPolicyUrl
   * @return (java.lang.String)
   */
  public static final native String Mdfl4F0j();

  /**
   * org.chromium.android_webview.AwContentsStatics.getUnreachableWebDataUrl
   * @return (java.lang.String)
   */
  public static final native String M0AyjO$E();

  /**
   * org.chromium.android_webview.AwContentsStatics.isMultiProcessEnabled
   * @return (boolean)
   */
  public static final native boolean M04mALrd();

  /**
   * org.chromium.android_webview.AwContentsStatics.logCommandLineForDebugging
   * @return (void)
   */
  public static final native void MjT_gThK();

  /**
   * org.chromium.android_webview.AwContentsStatics.setCheckClearTextPermitted
   * @param permitted (boolean)
   * @return (void)
   */
  public static final native void Mu0fMVv8(boolean permitted);

  /**
   * org.chromium.android_webview.AwContentsStatics.setSafeBrowsingWhitelist
   * @param urls (java.lang.String[])
   * @param callback (org.chromium.base.Callback<java.lang.Boolean>)
   * @return (void)
   */
  public static final native void MlIL02rX(String[] urls, Object callback);

  /**
   * org.chromium.android_webview.AwContentsStatics.setServiceWorkerIoThreadClient
   * @param ioThreadClient (org.chromium.android_webview.AwContentsIoThreadClient)
   * @param browserContext (org.chromium.android_webview.AwBrowserContext)
   * @return (void)
   */
  public static final native void MhYNFMfv(Object ioThreadClient, Object browserContext);

  /**
   * org.chromium.android_webview.AwCookieManager.flushCookieStore
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (void)
   */
  public static final native void MgWRfeHz(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.getAllowFileSchemeCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (boolean)
   */
  public static final native boolean MjZje8ZY(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.getCookie
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param url (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String MwtyXc6D(long nativeCookieManager, Object caller, String url);

  /**
   * org.chromium.android_webview.AwCookieManager.getDefaultCookieManager
   * @return (long)
   */
  public static final native long M2x3bkF7();

  /**
   * org.chromium.android_webview.AwCookieManager.getShouldAcceptCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (boolean)
   */
  public static final native boolean MIaWBQxt(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.hasCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (boolean)
   */
  public static final native boolean MLEl9vQp(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.removeAllCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param callback (org.chromium.android_webview.AwCookieManager.CookieCallback)
   * @return (void)
   */
  public static final native void MYNMnyIh(long nativeCookieManager, Object caller,
      Object callback);

  /**
   * org.chromium.android_webview.AwCookieManager.removeAllCookiesSync
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (void)
   */
  public static final native void M8tXWfBc(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.removeExpiredCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (void)
   */
  public static final native void MtpZW_Jk(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.removeSessionCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param callback (org.chromium.android_webview.AwCookieManager.CookieCallback)
   * @return (void)
   */
  public static final native void MPH4p3lP(long nativeCookieManager, Object caller,
      Object callback);

  /**
   * org.chromium.android_webview.AwCookieManager.removeSessionCookiesSync
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @return (void)
   */
  public static final native void MCvO0Hcd(long nativeCookieManager, Object caller);

  /**
   * org.chromium.android_webview.AwCookieManager.setAllowFileSchemeCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param allow (boolean)
   * @return (void)
   */
  public static final native void Mfo4YHeg(long nativeCookieManager, Object caller, boolean allow);

  /**
   * org.chromium.android_webview.AwCookieManager.setCookie
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param url (java.lang.String)
   * @param value (java.lang.String)
   * @param callback (org.chromium.android_webview.AwCookieManager.CookieCallback)
   * @return (void)
   */
  public static final native void MqWxZVFj(long nativeCookieManager, Object caller, String url,
      String value, Object callback);

  /**
   * org.chromium.android_webview.AwCookieManager.setCookieSync
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param url (java.lang.String)
   * @param value (java.lang.String)
   * @return (void)
   */
  public static final native void M521ruQI(long nativeCookieManager, Object caller, String url,
      String value);

  /**
   * org.chromium.android_webview.AwCookieManager.setShouldAcceptCookies
   * @param nativeCookieManager (long)
   * @param caller (org.chromium.android_webview.AwCookieManager)
   * @param accept (boolean)
   * @return (void)
   */
  public static final native void MxGz1CMI(long nativeCookieManager, Object caller, boolean accept);

  /**
   * org.chromium.android_webview.AwDebug.dumpWithoutCrashing
   * @param dumpPath (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MmSf62mU(String dumpPath);

  /**
   * org.chromium.android_webview.AwDebug.initCrashKeysForWebViewTesting
   * @return (void)
   */
  public static final native void MDJuylSA();

  /**
   * org.chromium.android_webview.AwDebug.setNonWhiteListedKeyForTesting
   * @return (void)
   */
  public static final native void MNM504jU();

  /**
   * org.chromium.android_webview.AwDebug.setSupportLibraryWebkitVersionCrashKey
   * @param version (java.lang.String)
   * @return (void)
   */
  public static final native void M06DsVuS(String version);

  /**
   * org.chromium.android_webview.AwDebug.setWhiteListedKeyForTesting
   * @return (void)
   */
  public static final native void M7oEM7wa();

  /**
   * org.chromium.android_webview.AwDevToolsServer.destroyRemoteDebugging
   * @param caller (org.chromium.android_webview.AwDevToolsServer)
   * @param devToolsServer (long)
   * @return (void)
   */
  public static final native void MQr9muLU(Object caller, long devToolsServer);

  /**
   * org.chromium.android_webview.AwDevToolsServer.initRemoteDebugging
   * @param caller (org.chromium.android_webview.AwDevToolsServer)
   * @return (long)
   */
  public static final native long MavwYLrk(Object caller);

  /**
   * org.chromium.android_webview.AwDevToolsServer.setRemoteDebuggingEnabled
   * @param caller (org.chromium.android_webview.AwDevToolsServer)
   * @param devToolsServer (long)
   * @param enabled (boolean)
   * @return (void)
   */
  public static final native void MQE$FZ2u(Object caller, long devToolsServer, boolean enabled);

  /**
   * org.chromium.android_webview.AwFeatureList.isEnabled
   * @param featureName (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MA_KcuN3(String featureName);

  /**
   * org.chromium.android_webview.AwFormDatabase.clearFormData
   * @return (void)
   */
  public static final native void MonDM6EC();

  /**
   * org.chromium.android_webview.AwFormDatabase.hasFormData
   * @return (boolean)
   */
  public static final native boolean MxzPtFuv();

  /**
   * org.chromium.android_webview.AwHttpAuthHandler.cancel
   * @param nativeAwHttpAuthHandler (long)
   * @param caller (org.chromium.android_webview.AwHttpAuthHandler)
   * @return (void)
   */
  public static final native void MylO8zte(long nativeAwHttpAuthHandler, Object caller);

  /**
   * org.chromium.android_webview.AwHttpAuthHandler.proceed
   * @param nativeAwHttpAuthHandler (long)
   * @param caller (org.chromium.android_webview.AwHttpAuthHandler)
   * @param username (java.lang.String)
   * @param password (java.lang.String)
   * @return (void)
   */
  public static final native void MWR2vWXA(long nativeAwHttpAuthHandler, Object caller,
      String username, String password);

  /**
   * org.chromium.android_webview.AwPacProcessor.getDefaultPacProcessor
   * @return (long)
   */
  public static final native long Mf2TcTCl();

  /**
   * org.chromium.android_webview.AwPacProcessor.makeProxyRequest
   * @param nativeAwPacProcessor (long)
   * @param caller (org.chromium.android_webview.AwPacProcessor)
   * @param url (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String ME9i0MKK(long nativeAwPacProcessor, Object caller, String url);

  /**
   * org.chromium.android_webview.AwPacProcessor.setProxyScript
   * @param nativeAwPacProcessor (long)
   * @param caller (org.chromium.android_webview.AwPacProcessor)
   * @param script (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MEjwJwuS(long nativeAwPacProcessor, Object caller,
      String script);

  /**
   * org.chromium.android_webview.AwPdfExporter.exportToPdf
   * @param nativeAwPdfExporter (long)
   * @param caller (org.chromium.android_webview.AwPdfExporter)
   * @param fd (int)
   * @param pages (int[])
   * @param cancellationSignal (android.os.CancellationSignal)
   * @return (void)
   */
  public static final native void Mp2j15Oh(long nativeAwPdfExporter, Object caller, int fd,
      int[] pages, Object cancellationSignal);

  /**
   * org.chromium.android_webview.AwProxyController.clearProxyOverride
   * @param caller (org.chromium.android_webview.AwProxyController)
   * @param listener (java.lang.Runnable)
   * @param executor (java.util.concurrent.Executor)
   * @return (void)
   */
  public static final native void Mx5cEreM(Object caller, Object listener, Object executor);

  /**
   * org.chromium.android_webview.AwProxyController.setProxyOverride
   * @param caller (org.chromium.android_webview.AwProxyController)
   * @param urlSchemes (java.lang.String[])
   * @param proxyUrls (java.lang.String[])
   * @param bypassRules (java.lang.String[])
   * @param listener (java.lang.Runnable)
   * @param executor (java.util.concurrent.Executor)
   * @return (java.lang.String)
   */
  public static final native String M8RBhX3H(Object caller, String[] urlSchemes, String[] proxyUrls,
      String[] bypassRules, Object listener, Object executor);

  /**
   * org.chromium.android_webview.AwQuotaManagerBridge.deleteAllData
   * @param nativeAwQuotaManagerBridge (long)
   * @param caller (org.chromium.android_webview.AwQuotaManagerBridge)
   * @return (void)
   */
  public static final native void MMBD8oze(long nativeAwQuotaManagerBridge, Object caller);

  /**
   * org.chromium.android_webview.AwQuotaManagerBridge.deleteOrigin
   * @param nativeAwQuotaManagerBridge (long)
   * @param caller (org.chromium.android_webview.AwQuotaManagerBridge)
   * @param origin (java.lang.String)
   * @return (void)
   */
  public static final native void MVmZoL1a(long nativeAwQuotaManagerBridge, Object caller,
      String origin);

  /**
   * org.chromium.android_webview.AwQuotaManagerBridge.getOrigins
   * @param nativeAwQuotaManagerBridge (long)
   * @param caller (org.chromium.android_webview.AwQuotaManagerBridge)
   * @param callbackId (int)
   * @return (void)
   */
  public static final native void MBqEItUo(long nativeAwQuotaManagerBridge, Object caller,
      int callbackId);

  /**
   * org.chromium.android_webview.AwQuotaManagerBridge.getUsageAndQuotaForOrigin
   * @param nativeAwQuotaManagerBridge (long)
   * @param caller (org.chromium.android_webview.AwQuotaManagerBridge)
   * @param origin (java.lang.String)
   * @param callbackId (int)
   * @param isQuota (boolean)
   * @return (void)
   */
  public static final native void MJn4yzAu(long nativeAwQuotaManagerBridge, Object caller,
      String origin, int callbackId, boolean isQuota);

  /**
   * org.chromium.android_webview.AwQuotaManagerBridge.init
   * @param nativeAwQuotaManagerBridge (long)
   * @param caller (org.chromium.android_webview.AwQuotaManagerBridge)
   * @return (void)
   */
  public static final native void MIrzsg_q(long nativeAwQuotaManagerBridge, Object caller);

  /**
   * org.chromium.android_webview.AwRenderProcess.terminateChildProcess
   * @param nativeAwRenderProcess (long)
   * @param caller (org.chromium.android_webview.AwRenderProcess)
   * @return (boolean)
   */
  public static final native boolean MjS72mtS(long nativeAwRenderProcess, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.destroy
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void MtdU4vpL(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.getDefaultUserAgent
   * @return (java.lang.String)
   */
  public static final native String MEzAefkM();

  /**
   * org.chromium.android_webview.AwSettings.init
   * @param caller (org.chromium.android_webview.AwSettings)
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (long)
   */
  public static final native long M4GPw_sx(Object caller, Object webContents);

  /**
   * org.chromium.android_webview.AwSettings.populateWebPreferencesLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @param webPrefsPtr (long)
   * @return (void)
   */
  public static final native void MrAp8rc4(long nativeAwSettings, Object caller, long webPrefsPtr);

  /**
   * org.chromium.android_webview.AwSettings.resetScrollAndScaleState
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void MYBohkOD(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateAllowFileAccessLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void M_GO18v7(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateCookiePolicyLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void M2EmJ2$z(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateEverythingLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void Mq8l4Aae(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateFormDataPreferencesLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void Mt45ai_h(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateInitialPageScaleLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void ManPyeB5(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateOffscreenPreRasterLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void ML5KB9Yq(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateRendererPreferencesLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void MbLkcpTV(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateUserAgentLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void MShmU87b(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateWebkitPreferencesLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void MuI9Jt0j(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwSettings.updateWillSuppressErrorStateLocked
   * @param nativeAwSettings (long)
   * @param caller (org.chromium.android_webview.AwSettings)
   * @return (void)
   */
  public static final native void MVXG782O(long nativeAwSettings, Object caller);

  /**
   * org.chromium.android_webview.AwTracingController.init
   * @param caller (org.chromium.android_webview.AwTracingController)
   * @return (long)
   */
  public static final native long MJiQrQ3Z(Object caller);

  /**
   * org.chromium.android_webview.AwTracingController.isTracing
   * @param nativeAwTracingController (long)
   * @param caller (org.chromium.android_webview.AwTracingController)
   * @return (boolean)
   */
  public static final native boolean MI9fwsnY(long nativeAwTracingController, Object caller);

  /**
   * org.chromium.android_webview.AwTracingController.start
   * @param nativeAwTracingController (long)
   * @param caller (org.chromium.android_webview.AwTracingController)
   * @param categories (java.lang.String)
   * @param traceMode (int)
   * @return (boolean)
   */
  public static final native boolean MDhATp5G(long nativeAwTracingController, Object caller,
      String categories, int traceMode);

  /**
   * org.chromium.android_webview.AwTracingController.stopAndFlush
   * @param nativeAwTracingController (long)
   * @param caller (org.chromium.android_webview.AwTracingController)
   * @return (boolean)
   */
  public static final native boolean MVnr_0Jw(long nativeAwTracingController, Object caller);

  /**
   * org.chromium.android_webview.AwWebContentsDelegate.filesSelectedInChooser
   * @param processId (int)
   * @param renderId (int)
   * @param modeFlags (int)
   * @param filePath (java.lang.String[])
   * @param displayName (java.lang.String[])
   * @return (void)
   */
  public static final native void MB5V$olG(int processId, int renderId, int modeFlags,
      String[] filePath, String[] displayName);

  /**
   * org.chromium.android_webview.JsReplyProxy.postMessage
   * @param nativeJsReplyProxy (long)
   * @param message (java.lang.String)
   * @return (void)
   */
  public static final native void MayS5i9E(long nativeJsReplyProxy, String message);

  /**
   * org.chromium.android_webview.PopupTouchHandleDrawable.init
   * @param caller (org.chromium.android_webview.PopupTouchHandleDrawable)
   * @param horizontalPaddingRatio (float)
   * @return (long)
   */
  public static final native long MQ7e2Y0w(Object caller, float horizontalPaddingRatio);

  /**
   * org.chromium.android_webview.gfx.AwDrawFnImpl.create
   * @return (long)
   */
  public static final native long M_e6WGre();

  /**
   * org.chromium.android_webview.gfx.AwDrawFnImpl.getCompositorFrameConsumer
   * @param nativeAwDrawFnImpl (long)
   * @param caller (org.chromium.android_webview.gfx.AwDrawFnImpl)
   * @return (long)
   */
  public static final native long MyqeD0HT(long nativeAwDrawFnImpl, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwDrawFnImpl.getFunctorHandle
   * @param nativeAwDrawFnImpl (long)
   * @param caller (org.chromium.android_webview.gfx.AwDrawFnImpl)
   * @return (int)
   */
  public static final native int MVv$dooB(long nativeAwDrawFnImpl, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwDrawFnImpl.releaseHandle
   * @param nativeAwDrawFnImpl (long)
   * @param caller (org.chromium.android_webview.gfx.AwDrawFnImpl)
   * @return (void)
   */
  public static final native void MTNG5d$d(long nativeAwDrawFnImpl, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwDrawFnImpl.setDrawFnFunctionTable
   * @param functionTablePointer (long)
   * @return (void)
   */
  public static final native void Muf_UBRy(long functionTablePointer);

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.create
   * @param javaProxy (org.chromium.android_webview.gfx.AwGLFunctor)
   * @return (long)
   */
  public static final native long Me9QwrxV(Object javaProxy);

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.deleteHardwareRenderer
   * @param nativeAwGLFunctor (long)
   * @param caller (org.chromium.android_webview.gfx.AwGLFunctor)
   * @return (void)
   */
  public static final native void MsCe5UVl(long nativeAwGLFunctor, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.destroy
   * @param nativeAwGLFunctor (long)
   * @return (void)
   */
  public static final native void Ms3_fBgF(long nativeAwGLFunctor);

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.getAwDrawGLFunction
   * @return (long)
   */
  public static final native long Mq4IKpgt();

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.getCompositorFrameConsumer
   * @param nativeAwGLFunctor (long)
   * @param caller (org.chromium.android_webview.gfx.AwGLFunctor)
   * @return (long)
   */
  public static final native long MfRoRhka(long nativeAwGLFunctor, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.getNativeInstanceCount
   * @return (int)
   */
  public static final native int MW0m24ct();

  /**
   * org.chromium.android_webview.gfx.AwGLFunctor.removeFromCompositorFrameProducer
   * @param nativeAwGLFunctor (long)
   * @param caller (org.chromium.android_webview.gfx.AwGLFunctor)
   * @return (void)
   */
  public static final native void MOiMYd0I(long nativeAwGLFunctor, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwPicture.destroy
   * @param nativeAwPicture (long)
   * @return (void)
   */
  public static final native void Mt$FsvYN(long nativeAwPicture);

  /**
   * org.chromium.android_webview.gfx.AwPicture.draw
   * @param nativeAwPicture (long)
   * @param caller (org.chromium.android_webview.gfx.AwPicture)
   * @param canvas (android.graphics.Canvas)
   * @return (void)
   */
  public static final native void MU5yPjvq(long nativeAwPicture, Object caller, Object canvas);

  /**
   * org.chromium.android_webview.gfx.AwPicture.getHeight
   * @param nativeAwPicture (long)
   * @param caller (org.chromium.android_webview.gfx.AwPicture)
   * @return (int)
   */
  public static final native int MAAuagRx(long nativeAwPicture, Object caller);

  /**
   * org.chromium.android_webview.gfx.AwPicture.getWidth
   * @param nativeAwPicture (long)
   * @param caller (org.chromium.android_webview.gfx.AwPicture)
   * @return (int)
   */
  public static final native int MxvjfQIM(long nativeAwPicture, Object caller);

  /**
   * org.chromium.android_webview.gfx.RootBeginFrameSourceWebView.onUpdateRefreshRate
   * @param nativeRootBeginFrameSourceWebView (long)
   * @param caller (org.chromium.android_webview.gfx.RootBeginFrameSourceWebView)
   * @param refreshRate (float)
   * @return (void)
   */
  public static final native void MsBIPWH$(long nativeRootBeginFrameSourceWebView, Object caller,
      float refreshRate);

  /**
   * org.chromium.android_webview.metrics.AwMetricsServiceClient.setFastStartupForTesting
   * @param fastStartupForTesting (boolean)
   * @return (void)
   */
  public static final native void M3qPS3Ay(boolean fastStartupForTesting);

  /**
   * org.chromium.android_webview.metrics.AwMetricsServiceClient.setHaveMetricsConsent
   * @param userConsent (boolean)
   * @param appConsent (boolean)
   * @return (void)
   */
  public static final native void Mdl6A1eo(boolean userConsent, boolean appConsent);

  /**
   * org.chromium.android_webview.metrics.AwMetricsServiceClient.setUploadIntervalForTesting
   * @param uploadIntervalMs (long)
   * @return (void)
   */
  public static final native void Mo7ROkjk(long uploadIntervalMs);

  /**
   * org.chromium.android_webview.permission.AwPermissionRequest.destroy
   * @param nativeAwPermissionRequest (long)
   * @return (void)
   */
  public static final native void MhKumtZE(long nativeAwPermissionRequest);

  /**
   * org.chromium.android_webview.permission.AwPermissionRequest.onAccept
   * @param nativeAwPermissionRequest (long)
   * @param caller (org.chromium.android_webview.permission.AwPermissionRequest)
   * @param allowed (boolean)
   * @return (void)
   */
  public static final native void Mk3Msvx7(long nativeAwPermissionRequest, Object caller,
      boolean allowed);
}
