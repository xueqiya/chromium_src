package J;

import java.lang.Object;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.device.sensors.PlatformSensor.notifyPlatformSensorError
   * @param nativePlatformSensorAndroid (long)
   * @param caller (org.chromium.device.sensors.PlatformSensor)
   * @return (void)
   */
  public static final native void MrHXg7he(long nativePlatformSensorAndroid, Object caller);

  /**
   * org.chromium.device.sensors.PlatformSensor.updatePlatformSensorReading
   * @param nativePlatformSensorAndroid (long)
   * @param caller (org.chromium.device.sensors.PlatformSensor)
   * @param timestamp (double)
   * @param value1 (double)
   * @param value2 (double)
   * @param value3 (double)
   * @param value4 (double)
   * @return (void)
   */
  public static final native void Mb4JvlL7(long nativePlatformSensorAndroid, Object caller,
      double timestamp, double value1, double value2, double value3, double value4);
}
