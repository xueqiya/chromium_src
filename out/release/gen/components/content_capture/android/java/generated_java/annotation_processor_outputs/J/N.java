package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.components.content_capture.ContentCaptureController.init
   * @param contentCaptureController (java.lang.Object)
   * @return (long)
   */
  public static final native long MM$06MFa(Object contentCaptureController);

  /**
   * org.chromium.components.content_capture.ContentCaptureController.setWhitelist
   * @param nativeContentCaptureController (long)
   * @param caller (org.chromium.components.content_capture.ContentCaptureController)
   * @param whitelist (java.lang.String[])
   * @param isRegex (boolean[])
   * @return (void)
   */
  public static final native void MMJ$SEno(long nativeContentCaptureController, Object caller,
      String[] whitelist, boolean[] isRegex);

  /**
   * org.chromium.components.content_capture.ContentCaptureFeatures.isEnabled
   * @return (boolean)
   */
  public static final native boolean MRrWU$ia();

  /**
   * org.chromium.components.content_capture.ContentCaptureReceiverManager.createOrGet
   * @param webContents (org.chromium.content_public.browser.WebContents)
   * @return (org.chromium.components.content_capture.ContentCaptureReceiverManager)
   */
  public static final native Object MxegY8Dy(Object webContents);
}
