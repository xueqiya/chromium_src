package J;

import java.lang.Object;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.device.usb.ChromeUsbService.deviceAttached
   * @param nativeUsbServiceAndroid (long)
   * @param caller (org.chromium.device.usb.ChromeUsbService)
   * @param device (android.hardware.usb.UsbDevice)
   * @return (void)
   */
  public static final native void MNmyS$Xi(long nativeUsbServiceAndroid, Object caller,
      Object device);

  /**
   * org.chromium.device.usb.ChromeUsbService.deviceDetached
   * @param nativeUsbServiceAndroid (long)
   * @param caller (org.chromium.device.usb.ChromeUsbService)
   * @param deviceId (int)
   * @return (void)
   */
  public static final native void MrBuy2sN(long nativeUsbServiceAndroid, Object caller,
      int deviceId);

  /**
   * org.chromium.device.usb.ChromeUsbService.devicePermissionRequestComplete
   * @param nativeUsbServiceAndroid (long)
   * @param caller (org.chromium.device.usb.ChromeUsbService)
   * @param deviceId (int)
   * @param granted (boolean)
   * @return (void)
   */
  public static final native void MDvFAfgT(long nativeUsbServiceAndroid, Object caller,
      int deviceId, boolean granted);
}
