package J;

import java.lang.Object;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.mojo.system.impl.BaseRunLoop.createBaseRunLoop
   * @param caller (org.chromium.mojo.system.impl.BaseRunLoop)
   * @return (long)
   */
  public static final native long MOJ55i7J(Object caller);

  /**
   * org.chromium.mojo.system.impl.BaseRunLoop.deleteMessageLoop
   * @param caller (org.chromium.mojo.system.impl.BaseRunLoop)
   * @param runLoopID (long)
   * @return (void)
   */
  public static final native void MEexSuCr(Object caller, long runLoopID);

  /**
   * org.chromium.mojo.system.impl.BaseRunLoop.postDelayedTask
   * @param caller (org.chromium.mojo.system.impl.BaseRunLoop)
   * @param runLoopID (long)
   * @param runnable (java.lang.Runnable)
   * @param delay (long)
   * @return (void)
   */
  public static final native void Mg$AGbqU(Object caller, long runLoopID, Object runnable,
      long delay);

  /**
   * org.chromium.mojo.system.impl.BaseRunLoop.quit
   * @param caller (org.chromium.mojo.system.impl.BaseRunLoop)
   * @return (void)
   */
  public static final native void MvPYY0Pk(Object caller);

  /**
   * org.chromium.mojo.system.impl.BaseRunLoop.run
   * @param caller (org.chromium.mojo.system.impl.BaseRunLoop)
   * @return (void)
   */
  public static final native void MWXT8JHC(Object caller);

  /**
   * org.chromium.mojo.system.impl.BaseRunLoop.runUntilIdle
   * @param caller (org.chromium.mojo.system.impl.BaseRunLoop)
   * @return (void)
   */
  public static final native void MeWGVAnX(Object caller);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.beginReadData
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param numBytes (int)
   * @param flags (int)
   * @return (org.chromium.mojo.system.ResultAnd<java.nio.ByteBuffer>)
   */
  public static final native Object M_DxS0Vi(Object caller, int mojoHandle, int numBytes,
      int flags);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.beginWriteData
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param numBytes (int)
   * @param flags (int)
   * @return (org.chromium.mojo.system.ResultAnd<java.nio.ByteBuffer>)
   */
  public static final native Object M100xOXT(Object caller, int mojoHandle, int numBytes,
      int flags);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.close
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @return (int)
   */
  public static final native int MLQe1QEw(Object caller, int mojoHandle);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.createDataPipe
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param optionsBuffer (java.nio.ByteBuffer)
   * @return (org.chromium.mojo.system.ResultAnd<org.chromium.mojo.system.impl.CoreImpl.IntegerPair>)
   */
  public static final native Object MhNaf1lV(Object caller, Object optionsBuffer);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.createMessagePipe
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param optionsBuffer (java.nio.ByteBuffer)
   * @return (org.chromium.mojo.system.ResultAnd<org.chromium.mojo.system.impl.CoreImpl.IntegerPair>)
   */
  public static final native Object MZhgS7uU(Object caller, Object optionsBuffer);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.createSharedBuffer
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param optionsBuffer (java.nio.ByteBuffer)
   * @param numBytes (long)
   * @return (org.chromium.mojo.system.ResultAnd<java.lang.Integer>)
   */
  public static final native Object MZ0nRPS0(Object caller, Object optionsBuffer, long numBytes);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.duplicate
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param optionsBuffer (java.nio.ByteBuffer)
   * @return (org.chromium.mojo.system.ResultAnd<java.lang.Integer>)
   */
  public static final native Object M6nJbV6M(Object caller, int mojoHandle, Object optionsBuffer);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.endReadData
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param numBytesRead (int)
   * @return (int)
   */
  public static final native int MC3EsLAG(Object caller, int mojoHandle, int numBytesRead);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.endWriteData
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param numBytesWritten (int)
   * @return (int)
   */
  public static final native int MBed1sI2(Object caller, int mojoHandle, int numBytesWritten);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.getNativeBufferOffset
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param buffer (java.nio.ByteBuffer)
   * @param alignment (int)
   * @return (int)
   */
  public static final native int MBIRtXF8(Object caller, Object buffer, int alignment);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.getTimeTicksNow
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @return (long)
   */
  public static final native long M48BvrvK(Object caller);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.map
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param offset (long)
   * @param numBytes (long)
   * @param flags (int)
   * @return (org.chromium.mojo.system.ResultAnd<java.nio.ByteBuffer>)
   */
  public static final native Object Mm6zKFIo(Object caller, int mojoHandle, long offset,
      long numBytes, int flags);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.queryHandleSignalsState
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param signalsStateBuffer (java.nio.ByteBuffer)
   * @return (int)
   */
  public static final native int MJr0GcyT(Object caller, int mojoHandle, Object signalsStateBuffer);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.readData
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param elements (java.nio.ByteBuffer)
   * @param elementsSize (int)
   * @param flags (int)
   * @return (org.chromium.mojo.system.ResultAnd<java.lang.Integer>)
   */
  public static final native Object MBDORBtR(Object caller, int mojoHandle, Object elements,
      int elementsSize, int flags);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.readMessage
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param flags (int)
   * @return (org.chromium.mojo.system.ResultAnd<org.chromium.mojo.system.MessagePipeHandle.ReadMessageResult>)
   */
  public static final native Object MEHdfwD0(Object caller, int mojoHandle, int flags);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.unmap
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param buffer (java.nio.ByteBuffer)
   * @return (int)
   */
  public static final native int MC_p8PYl(Object caller, Object buffer);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.writeData
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param elements (java.nio.ByteBuffer)
   * @param limit (int)
   * @param flags (int)
   * @return (org.chromium.mojo.system.ResultAnd<java.lang.Integer>)
   */
  public static final native Object Mra2dnT9(Object caller, int mojoHandle, Object elements,
      int limit, int flags);

  /**
   * org.chromium.mojo.system.impl.CoreImpl.writeMessage
   * @param caller (org.chromium.mojo.system.impl.CoreImpl)
   * @param mojoHandle (int)
   * @param bytes (java.nio.ByteBuffer)
   * @param numBytes (int)
   * @param handlesBuffer (java.nio.ByteBuffer)
   * @param flags (int)
   * @return (int)
   */
  public static final native int Mkun8eIV(Object caller, int mojoHandle, Object bytes, int numBytes,
      Object handlesBuffer, int flags);

  /**
   * org.chromium.mojo.system.impl.WatcherImpl.cancel
   * @param caller (org.chromium.mojo.system.impl.WatcherImpl)
   * @param implPtr (long)
   * @return (void)
   */
  public static final native void MPTT407x(Object caller, long implPtr);

  /**
   * org.chromium.mojo.system.impl.WatcherImpl.createWatcher
   * @param caller (org.chromium.mojo.system.impl.WatcherImpl)
   * @return (long)
   */
  public static final native long MXGgOw9k(Object caller);

  /**
   * org.chromium.mojo.system.impl.WatcherImpl.delete
   * @param caller (org.chromium.mojo.system.impl.WatcherImpl)
   * @param implPtr (long)
   * @return (void)
   */
  public static final native void Mi32vqDA(Object caller, long implPtr);

  /**
   * org.chromium.mojo.system.impl.WatcherImpl.start
   * @param caller (org.chromium.mojo.system.impl.WatcherImpl)
   * @param implPtr (long)
   * @param mojoHandle (int)
   * @param flags (int)
   * @return (int)
   */
  public static final native int MOmBVeTt(Object caller, long implPtr, int mojoHandle, int flags);
}
