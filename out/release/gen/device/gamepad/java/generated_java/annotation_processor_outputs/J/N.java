package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.device.gamepad.GamepadList.setGamepadData
   * @param caller (org.chromium.device.gamepad.GamepadList)
   * @param webGamepadsPtr (long)
   * @param index (int)
   * @param mapping (boolean)
   * @param connected (boolean)
   * @param devicename (java.lang.String)
   * @param timestamp (long)
   * @param axes (float[])
   * @param buttons (float[])
   * @return (void)
   */
  public static final native void MOkngxPY(Object caller, long webGamepadsPtr, int index,
      boolean mapping, boolean connected, String devicename, long timestamp, float[] axes,
      float[] buttons);
}
