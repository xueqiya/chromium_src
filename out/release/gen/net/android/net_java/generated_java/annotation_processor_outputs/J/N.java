package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.net.GURLUtils.getOrigin
   * @param url (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String MpCt7siL(String url);

  /**
   * org.chromium.net.GURLUtils.getScheme
   * @param url (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String M$mITdbo(String url);

  /**
   * org.chromium.net.HttpNegotiateAuthenticator.setResult
   * @param nativeJavaNegotiateResultWrapper (long)
   * @param caller (org.chromium.net.HttpNegotiateAuthenticator)
   * @param status (int)
   * @param authToken (java.lang.String)
   * @return (void)
   */
  public static final native void M0s8NeYn(long nativeJavaNegotiateResultWrapper, Object caller,
      int status, String authToken);

  /**
   * org.chromium.net.HttpUtil.isAllowedHeader
   * @param headerName (java.lang.String)
   * @param headerValue (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MorcXgQd(String headerName, String headerValue);

  /**
   * org.chromium.net.NetworkChangeNotifier.notifyConnectionTypeChanged
   * @param nativePtr (long)
   * @param caller (org.chromium.net.NetworkChangeNotifier)
   * @param newConnectionType (int)
   * @param defaultNetId (long)
   * @return (void)
   */
  public static final native void MbPIImnU(long nativePtr, Object caller, int newConnectionType,
      long defaultNetId);

  /**
   * org.chromium.net.NetworkChangeNotifier.notifyMaxBandwidthChanged
   * @param nativePtr (long)
   * @param caller (org.chromium.net.NetworkChangeNotifier)
   * @param subType (int)
   * @return (void)
   */
  public static final native void Mt26m31j(long nativePtr, Object caller, int subType);

  /**
   * org.chromium.net.NetworkChangeNotifier.notifyOfNetworkConnect
   * @param nativePtr (long)
   * @param caller (org.chromium.net.NetworkChangeNotifier)
   * @param netId (long)
   * @param connectionType (int)
   * @return (void)
   */
  public static final native void MBT1i5cd(long nativePtr, Object caller, long netId,
      int connectionType);

  /**
   * org.chromium.net.NetworkChangeNotifier.notifyOfNetworkDisconnect
   * @param nativePtr (long)
   * @param caller (org.chromium.net.NetworkChangeNotifier)
   * @param netId (long)
   * @return (void)
   */
  public static final native void MDpuHJTB(long nativePtr, Object caller, long netId);

  /**
   * org.chromium.net.NetworkChangeNotifier.notifyOfNetworkSoonToDisconnect
   * @param nativePtr (long)
   * @param caller (org.chromium.net.NetworkChangeNotifier)
   * @param netId (long)
   * @return (void)
   */
  public static final native void MiJIMrTb(long nativePtr, Object caller, long netId);

  /**
   * org.chromium.net.NetworkChangeNotifier.notifyPurgeActiveNetworkList
   * @param nativePtr (long)
   * @param caller (org.chromium.net.NetworkChangeNotifier)
   * @param activeNetIds (long[])
   * @return (void)
   */
  public static final native void MpF$179U(long nativePtr, Object caller, long[] activeNetIds);

  /**
   * org.chromium.net.ProxyChangeListener.proxySettingsChanged
   * @param nativePtr (long)
   * @param caller (org.chromium.net.ProxyChangeListener)
   * @return (void)
   */
  public static final native void MCIk73GZ(long nativePtr, Object caller);

  /**
   * org.chromium.net.ProxyChangeListener.proxySettingsChangedTo
   * @param nativePtr (long)
   * @param caller (org.chromium.net.ProxyChangeListener)
   * @param host (java.lang.String)
   * @param port (int)
   * @param pacUrl (java.lang.String)
   * @param exclusionList (java.lang.String[])
   * @return (void)
   */
  public static final native void MyoFZt$2(long nativePtr, Object caller, String host, int port,
      String pacUrl, String[] exclusionList);

  /**
   * org.chromium.net.X509Util.notifyKeyChainChanged
   * @return (void)
   */
  public static final native void MGVAvp19();
}
