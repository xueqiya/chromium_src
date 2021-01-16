/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.base;
/**
 * This interface is used to control child processes.
 */
public interface ITestController extends android.os.IInterface
{
  /** Default implementation for ITestController. */
  public static class Default implements org.chromium.base.ITestController
  {
    /**
       * Forces the service process to terminate and block until the process stops.
       * @param exitCode the exit code the process should terminate with.
       * @return always true, a return value is only returned to force the call to be synchronous.
       */
    @Override public boolean forceStopSynchronous(int exitCode) throws android.os.RemoteException
    {
      return false;
    }
    /**
       * Forces the service process to terminate.
       * @param exitCode the exit code the process should terminate with.
       */
    @Override public void forceStop(int exitCode) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.base.ITestController
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.base.ITestController";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.base.ITestController interface,
     * generating a proxy if needed.
     */
    public static org.chromium.base.ITestController asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.base.ITestController))) {
        return ((org.chromium.base.ITestController)iin);
      }
      return new org.chromium.base.ITestController.Stub.Proxy(obj);
    }
    @Override public android.os.IBinder asBinder()
    {
      return this;
    }
    @Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
    {
      java.lang.String descriptor = DESCRIPTOR;
      switch (code)
      {
        case INTERFACE_TRANSACTION:
        {
          reply.writeString(descriptor);
          return true;
        }
        case TRANSACTION_forceStopSynchronous:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          boolean _result = this.forceStopSynchronous(_arg0);
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_forceStop:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.forceStop(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.base.ITestController
    {
      private android.os.IBinder mRemote;
      Proxy(android.os.IBinder remote)
      {
        mRemote = remote;
      }
      @Override public android.os.IBinder asBinder()
      {
        return mRemote;
      }
      public java.lang.String getInterfaceDescriptor()
      {
        return DESCRIPTOR;
      }
      /**
         * Forces the service process to terminate and block until the process stops.
         * @param exitCode the exit code the process should terminate with.
         * @return always true, a return value is only returned to force the call to be synchronous.
         */
      @Override public boolean forceStopSynchronous(int exitCode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(exitCode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_forceStopSynchronous, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().forceStopSynchronous(exitCode);
          }
          _reply.readException();
          _result = (0!=_reply.readInt());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      /**
         * Forces the service process to terminate.
         * @param exitCode the exit code the process should terminate with.
         */
      @Override public void forceStop(int exitCode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(exitCode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_forceStop, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().forceStop(exitCode);
            return;
          }
        }
        finally {
          _data.recycle();
        }
      }
      public static org.chromium.base.ITestController sDefaultImpl;
    }
    static final int TRANSACTION_forceStopSynchronous = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_forceStop = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    public static boolean setDefaultImpl(org.chromium.base.ITestController impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.base.ITestController getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  /**
     * Forces the service process to terminate and block until the process stops.
     * @param exitCode the exit code the process should terminate with.
     * @return always true, a return value is only returned to force the call to be synchronous.
     */
  public boolean forceStopSynchronous(int exitCode) throws android.os.RemoteException;
  /**
     * Forces the service process to terminate.
     * @param exitCode the exit code the process should terminate with.
     */
  public void forceStop(int exitCode) throws android.os.RemoteException;
}
