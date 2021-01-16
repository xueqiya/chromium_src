package J;

import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.device.geolocation.LocationProviderAdapter.newErrorAvailable
   * @param message (java.lang.String)
   * @return (void)
   */
  public static final native void M8Iz7Ptw(String message);

  /**
   * org.chromium.device.geolocation.LocationProviderAdapter.newLocationAvailable
   * @param latitude (double)
   * @param longitude (double)
   * @param timeStamp (double)
   * @param hasAltitude (boolean)
   * @param altitude (double)
   * @param hasAccuracy (boolean)
   * @param accuracy (double)
   * @param hasHeading (boolean)
   * @param heading (double)
   * @param hasSpeed (boolean)
   * @param speed (double)
   * @return (void)
   */
  public static final native void MvJnRjJi(double latitude, double longitude, double timeStamp,
      boolean hasAltitude, double altitude, boolean hasAccuracy, double accuracy,
      boolean hasHeading, double heading, boolean hasSpeed, double speed);
}
