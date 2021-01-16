package J;

import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.components.safe_browsing.SafeBrowsingApiBridge.areLocalBlacklistsEnabled
   * @return (boolean)
   */
  public static final native boolean Mrgx57nB();

  /**
   * org.chromium.components.safe_browsing.SafeBrowsingApiBridge.onUrlCheckDone
   * @param callbackId (long)
   * @param resultStatus (int)
   * @param metadata (java.lang.String)
   * @param checkDelta (long)
   * @return (void)
   */
  public static final native void M3tDaVsh(long callbackId, int resultStatus, String metadata,
      long checkDelta);
}
