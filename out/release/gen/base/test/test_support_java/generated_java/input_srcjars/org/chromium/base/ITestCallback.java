/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.base;
/**
 * This interface is called by the child process to pass its controller to its parent.
 */
public interface ITestCallback extends android.os.IInterface
{
  /** Default implementation for ITestCallback. */
  public static class Default implements org.chromium.base.ITestCallback
  {
    @Override public void childConnected(org.chromium.base.ITestController controller) throws android.os.RemoteException
    {
    }
    /**
        * Invoked by the service to notify that the main method returned.
        * IMPORTANT! Should not be marked oneway as the caller will terminate the running process after
        * this call. Marking it oneway would make the call asynchronous and the process could terminate
        * before the call was actually sent.
        */
    @Override public void mainReturned(int returnCode) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.base.ITestCallback
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.base.ITestCallback";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.base.ITestCallback interface,
     * generating a proxy if needed.
     */
    public static org.chromium.base.ITestCallback asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.base.ITestCallback))) {
        return ((org.chromium.base.ITestCallback)iin);
      }
      return new org.chromium.base.ITestCallback.Stub.Proxy(obj);
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
        case TRANSACTION_childConnected:
        {
          data.enforceInterface(descriptor);
          org.chromium.base.ITestController _arg0;
          _arg0 = org.chromium.base.ITestController.Stub.asInterface(data.readStrongBinder());
          this.childConnected(_arg0);
          return true;
        }
        case TRANSACTION_mainReturned:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.mainReturned(_arg0);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.base.ITestCallback
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
      @Override public void childConnected(org.chromium.base.ITestController controller) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((controller!=null))?(controller.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_childConnected, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().childConnected(controller);
            return;
          }
        }
        finally {
          _data.recycle();
        }
      }
      /**
          * Invoked by the service to notify that the main method returned.
          * IMPORTANT! Should not be marked oneway as the caller will terminate the running process after
          * this call. Marking it oneway would make the call asynchronous and the process could terminate
          * before the call was actually sent.
          */
      @Override public void mainReturned(int returnCode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(returnCode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_mainReturned, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().mainReturned(returnCode);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      public static org.chromium.base.ITestCallback sDefaultImpl;
    }
    static final int TRANSACTION_childConnected = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_mainReturned = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    public static boolean setDefaultImpl(org.chromium.base.ITestCallback impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.base.ITestCallback getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public void childConnected(org.chromium.base.ITestController controller) throws android.os.RemoteException;
  /**
      * Invoked by the service to notify that the main method returned.
      * IMPORTANT! Should not be marked oneway as the caller will terminate the running process after
      * this call. Marking it oneway would make the call asynchronous and the process could terminate
      * before the call was actually sent.
      */
  public void mainReturned(int returnCode) throws android.os.RemoteException;
}
