/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.weblayer_private.interfaces;
/**
 * Allows the client to override the default way of handling user interactions
 * with error pages (such as SSL interstitials).
 */
public interface IErrorPageCallbackClient extends android.os.IInterface
{
  /** Default implementation for IErrorPageCallbackClient. */
  public static class Default implements org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient
  {
    @Override public boolean onBackToSafety() throws android.os.RemoteException
    {
      return false;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient interface,
     * generating a proxy if needed.
     */
    public static org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient))) {
        return ((org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient)iin);
      }
      return new org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient.Stub.Proxy(obj);
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
        case TRANSACTION_onBackToSafety:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.onBackToSafety();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient
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
      @Override public boolean onBackToSafety() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onBackToSafety, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().onBackToSafety();
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
      public static org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient sDefaultImpl;
    }
    static final int TRANSACTION_onBackToSafety = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    public static boolean setDefaultImpl(org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public boolean onBackToSafety() throws android.os.RemoteException;
}
