package J;

import java.lang.Object;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.midi.MidiInputPortAndroid.onData
   * @param nativeMidiInputPortAndroid (long)
   * @param bs (byte[])
   * @param offset (int)
   * @param count (int)
   * @param timestamp (long)
   * @return (void)
   */
  public static final native void MzDIdqgH(long nativeMidiInputPortAndroid, byte[] bs, int offset,
      int count, long timestamp);

  /**
   * org.chromium.midi.MidiManagerAndroid.onAttached
   * @param nativeMidiManagerAndroid (long)
   * @param device (org.chromium.midi.MidiDeviceAndroid)
   * @return (void)
   */
  public static final native void MEOWUhL5(long nativeMidiManagerAndroid, Object device);

  /**
   * org.chromium.midi.MidiManagerAndroid.onDetached
   * @param nativeMidiManagerAndroid (long)
   * @param device (org.chromium.midi.MidiDeviceAndroid)
   * @return (void)
   */
  public static final native void Md3XPFG5(long nativeMidiManagerAndroid, Object device);

  /**
   * org.chromium.midi.MidiManagerAndroid.onInitializationFailed
   * @param nativeMidiManagerAndroid (long)
   * @return (void)
   */
  public static final native void MfmZ2$zu(long nativeMidiManagerAndroid);

  /**
   * org.chromium.midi.MidiManagerAndroid.onInitialized
   * @param nativeMidiManagerAndroid (long)
   * @param devices (org.chromium.midi.MidiDeviceAndroid[])
   * @return (void)
   */
  public static final native void M3znzcE9(long nativeMidiManagerAndroid, Object[] devices);

  /**
   * org.chromium.midi.UsbMidiDeviceAndroid.onData
   * @param nativeUsbMidiDeviceAndroid (long)
   * @param endpointNumber (int)
   * @param data (byte[])
   * @return (void)
   */
  public static final native void MNGB4bj1(long nativeUsbMidiDeviceAndroid, int endpointNumber,
      byte[] data);

  /**
   * org.chromium.midi.UsbMidiDeviceFactoryAndroid.onUsbMidiDeviceAttached
   * @param nativeUsbMidiDeviceFactoryAndroid (long)
   * @param device (java.lang.Object)
   * @return (void)
   */
  public static final native void MGbhHafy(long nativeUsbMidiDeviceFactoryAndroid, Object device);

  /**
   * org.chromium.midi.UsbMidiDeviceFactoryAndroid.onUsbMidiDeviceDetached
   * @param nativeUsbMidiDeviceFactoryAndroid (long)
   * @param index (int)
   * @return (void)
   */
  public static final native void MQPqHj_p(long nativeUsbMidiDeviceFactoryAndroid, int index);

  /**
   * org.chromium.midi.UsbMidiDeviceFactoryAndroid.onUsbMidiDeviceRequestDone
   * @param nativeUsbMidiDeviceFactoryAndroid (long)
   * @param devices (java.lang.Object[])
   * @return (void)
   */
  public static final native void MrVQrlMA(long nativeUsbMidiDeviceFactoryAndroid,
      Object[] devices);
}
