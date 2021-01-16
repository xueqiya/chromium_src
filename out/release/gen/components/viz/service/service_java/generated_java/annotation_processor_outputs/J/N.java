package J;

import java.lang.Object;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.components.viz.service.frame_sinks.ExternalBeginFrameSourceAndroid.onVSync
   * @param nativeExternalBeginFrameSourceAndroid (long)
   * @param caller (org.chromium.components.viz.service.frame_sinks.ExternalBeginFrameSourceAndroid)
   * @param vsyncTimeMicros (long)
   * @param vsyncPeriodMicros (long)
   * @return (void)
   */
  public static final native void Mhc_M_H$(long nativeExternalBeginFrameSourceAndroid,
      Object caller, long vsyncTimeMicros, long vsyncPeriodMicros);
}
