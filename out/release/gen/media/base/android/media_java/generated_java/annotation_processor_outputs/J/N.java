package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.media.AudioManagerAndroid.setMute
   * @param nativeAudioManagerAndroid (long)
   * @param caller (org.chromium.media.AudioManagerAndroid)
   * @param muted (boolean)
   * @return (void)
   */
  public static final native void MCgftn_d(long nativeAudioManagerAndroid, Object caller,
      boolean muted);

  /**
   * org.chromium.media.AudioTrackOutputStream.getAddress
   * @param nativeAudioTrackOutputStream (long)
   * @param caller (org.chromium.media.AudioTrackOutputStream)
   * @param byteBuffer (java.nio.ByteBuffer)
   * @return (long)
   */
  public static final native long MMQ1O_vA(long nativeAudioTrackOutputStream, Object caller,
      Object byteBuffer);

  /**
   * org.chromium.media.AudioTrackOutputStream.onError
   * @param nativeAudioTrackOutputStream (long)
   * @param caller (org.chromium.media.AudioTrackOutputStream)
   * @return (void)
   */
  public static final native void Mr6$Ko2f(long nativeAudioTrackOutputStream, Object caller);

  /**
   * org.chromium.media.AudioTrackOutputStream.onMoreData
   * @param nativeAudioTrackOutputStream (long)
   * @param caller (org.chromium.media.AudioTrackOutputStream)
   * @param audioData (java.nio.ByteBuffer)
   * @param delayInFrames (long)
   * @return (org.chromium.media.AudioTrackOutputStream.AudioBufferInfo)
   */
  public static final native Object MEPH2V3G(long nativeAudioTrackOutputStream, Object caller,
      Object audioData, long delayInFrames);

  /**
   * org.chromium.media.HdrMetadata.colorTransfer
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (int)
   */
  public static final native int Myx2EYmS(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.maxContentLuminance
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (int)
   */
  public static final native int MMmvZ$nS(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.maxFrameAverageLuminance
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (int)
   */
  public static final native int MzRCryEE(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.maxMasteringLuminance
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MOL90CVq(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.minMasteringLuminance
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MM07Xk18(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaries
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (int)
   */
  public static final native int M6EY_9Mw(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaryBChromaticityX
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float McEG$Qxu(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaryBChromaticityY
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MU6WBitK(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaryGChromaticityX
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MRQrYl4t(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaryGChromaticityY
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MtgfnGGz(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaryRChromaticityX
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float Mc0wiJ8$(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.primaryRChromaticityY
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MYP0SLZ2(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.range
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (int)
   */
  public static final native int MGKRBsYQ(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.whitePointChromaticityX
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float M8pzdQ$h(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.HdrMetadata.whitePointChromaticityY
   * @param nativeJniHdrMetadata (long)
   * @param caller (org.chromium.media.HdrMetadata)
   * @return (float)
   */
  public static final native float MXbY07SE(long nativeJniHdrMetadata, Object caller);

  /**
   * org.chromium.media.MediaCodecBridge.onBuffersAvailable
   * @param nativeMediaCodecBridge (long)
   * @param caller (org.chromium.media.MediaCodecBridge)
   * @return (void)
   */
  public static final native void MNqjfk23(long nativeMediaCodecBridge, Object caller);

  /**
   * org.chromium.media.MediaDrmBridge.onMediaCryptoReady
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param mediaCrypto (android.media.MediaCrypto)
   * @return (void)
   */
  public static final native void MV9yuwVC(long nativeMediaDrmBridge, Object caller,
      Object mediaCrypto);

  /**
   * org.chromium.media.MediaDrmBridge.onPromiseRejected
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param promiseId (long)
   * @param errorMessage (java.lang.String)
   * @return (void)
   */
  public static final native void M2P7BQ98(long nativeMediaDrmBridge, Object caller, long promiseId,
      String errorMessage);

  /**
   * org.chromium.media.MediaDrmBridge.onPromiseResolved
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param promiseId (long)
   * @return (void)
   */
  public static final native void MOzXytse(long nativeMediaDrmBridge, Object caller,
      long promiseId);

  /**
   * org.chromium.media.MediaDrmBridge.onPromiseResolvedWithSession
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param promiseId (long)
   * @param emeSessionId (byte[])
   * @return (void)
   */
  public static final native void MtWWjNjU(long nativeMediaDrmBridge, Object caller, long promiseId,
      byte[] emeSessionId);

  /**
   * org.chromium.media.MediaDrmBridge.onProvisionRequest
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param defaultUrl (java.lang.String)
   * @param requestData (byte[])
   * @return (void)
   */
  public static final native void MmhSkOYV(long nativeMediaDrmBridge, Object caller,
      String defaultUrl, byte[] requestData);

  /**
   * org.chromium.media.MediaDrmBridge.onProvisioningComplete
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param success (boolean)
   * @return (void)
   */
  public static final native void MAaklmRW(long nativeMediaDrmBridge, Object caller,
      boolean success);

  /**
   * org.chromium.media.MediaDrmBridge.onSessionClosed
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param emeSessionId (byte[])
   * @return (void)
   */
  public static final native void MulYy5b7(long nativeMediaDrmBridge, Object caller,
      byte[] emeSessionId);

  /**
   * org.chromium.media.MediaDrmBridge.onSessionExpirationUpdate
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param emeSessionId (byte[])
   * @param expirationTime (long)
   * @return (void)
   */
  public static final native void MFLUFEZc(long nativeMediaDrmBridge, Object caller,
      byte[] emeSessionId, long expirationTime);

  /**
   * org.chromium.media.MediaDrmBridge.onSessionKeysChange
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param emeSessionId (byte[])
   * @param keysInfo (java.lang.Object[])
   * @param hasAdditionalUsableKey (boolean)
   * @param isKeyRelease (boolean)
   * @return (void)
   */
  public static final native void Mk8V79M2(long nativeMediaDrmBridge, Object caller,
      byte[] emeSessionId, Object[] keysInfo, boolean hasAdditionalUsableKey, boolean isKeyRelease);

  /**
   * org.chromium.media.MediaDrmBridge.onSessionMessage
   * @param nativeMediaDrmBridge (long)
   * @param caller (org.chromium.media.MediaDrmBridge)
   * @param emeSessionId (byte[])
   * @param requestType (int)
   * @param message (byte[])
   * @return (void)
   */
  public static final native void Mf7HZHqV(long nativeMediaDrmBridge, Object caller,
      byte[] emeSessionId, int requestType, byte[] message);

  /**
   * org.chromium.media.MediaDrmStorageBridge.onClearInfo
   * @param nativeMediaDrmStorageBridge (long)
   * @param caller (org.chromium.media.MediaDrmStorageBridge)
   * @param sessionId (byte[])
   * @param cb (org.chromium.base.Callback<java.lang.Boolean>)
   * @return (void)
   */
  public static final native void MYa_y6Dg(long nativeMediaDrmStorageBridge, Object caller,
      byte[] sessionId, Object cb);

  /**
   * org.chromium.media.MediaDrmStorageBridge.onLoadInfo
   * @param nativeMediaDrmStorageBridge (long)
   * @param caller (org.chromium.media.MediaDrmStorageBridge)
   * @param sessionId (byte[])
   * @param cb (org.chromium.base.Callback<org.chromium.media.MediaDrmStorageBridge.PersistentInfo>)
   * @return (void)
   */
  public static final native void Mmi_qOX8(long nativeMediaDrmStorageBridge, Object caller,
      byte[] sessionId, Object cb);

  /**
   * org.chromium.media.MediaDrmStorageBridge.onProvisioned
   * @param nativeMediaDrmStorageBridge (long)
   * @param caller (org.chromium.media.MediaDrmStorageBridge)
   * @param cb (org.chromium.base.Callback<java.lang.Boolean>)
   * @return (void)
   */
  public static final native void ME6vNmlv(long nativeMediaDrmStorageBridge, Object caller,
      Object cb);

  /**
   * org.chromium.media.MediaDrmStorageBridge.onSaveInfo
   * @param nativeMediaDrmStorageBridge (long)
   * @param caller (org.chromium.media.MediaDrmStorageBridge)
   * @param info (org.chromium.media.MediaDrmStorageBridge.PersistentInfo)
   * @param cb (org.chromium.base.Callback<java.lang.Boolean>)
   * @return (void)
   */
  public static final native void MeALR1v2(long nativeMediaDrmStorageBridge, Object caller,
      Object info, Object cb);

  /**
   * org.chromium.media.MediaPlayerBridge.onDidSetDataUriDataSource
   * @param nativeMediaPlayerBridge (long)
   * @param caller (org.chromium.media.MediaPlayerBridge)
   * @param success (boolean)
   * @return (void)
   */
  public static final native void Mo4Rd8TE(long nativeMediaPlayerBridge, Object caller,
      boolean success);

  /**
   * org.chromium.media.MediaPlayerListener.onMediaError
   * @param nativeMediaPlayerListener (long)
   * @param caller (org.chromium.media.MediaPlayerListener)
   * @param errorType (int)
   * @return (void)
   */
  public static final native void Myj2LnkZ(long nativeMediaPlayerListener, Object caller,
      int errorType);

  /**
   * org.chromium.media.MediaPlayerListener.onMediaPrepared
   * @param nativeMediaPlayerListener (long)
   * @param caller (org.chromium.media.MediaPlayerListener)
   * @return (void)
   */
  public static final native void MQTompEl(long nativeMediaPlayerListener, Object caller);

  /**
   * org.chromium.media.MediaPlayerListener.onPlaybackComplete
   * @param nativeMediaPlayerListener (long)
   * @param caller (org.chromium.media.MediaPlayerListener)
   * @return (void)
   */
  public static final native void MX$D6jYE(long nativeMediaPlayerListener, Object caller);

  /**
   * org.chromium.media.MediaPlayerListener.onVideoSizeChanged
   * @param nativeMediaPlayerListener (long)
   * @param caller (org.chromium.media.MediaPlayerListener)
   * @param width (int)
   * @param height (int)
   * @return (void)
   */
  public static final native void Mfq$ZJpW(long nativeMediaPlayerListener, Object caller, int width,
      int height);

  /**
   * org.chromium.media.MediaServerCrashListener.onMediaServerCrashDetected
   * @param nativeMediaServerCrashListener (long)
   * @param caller (org.chromium.media.MediaServerCrashListener)
   * @param watchdogNeedsRelease (boolean)
   * @return (void)
   */
  public static final native void Mm$QSrAo(long nativeMediaServerCrashListener, Object caller,
      boolean watchdogNeedsRelease);
}
