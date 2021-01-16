/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.weblayer_private.interfaces;
public interface IProfile extends android.os.IInterface
{
  /** Default implementation for IProfile. */
  public static class Default implements org.chromium.weblayer_private.interfaces.IProfile
  {
    @Override public void destroy() throws android.os.RemoteException
    {
    }
    @Override public void clearBrowsingData(int[] dataTypes, long fromMillis, long toMillis, org.chromium.weblayer_private.interfaces.IObjectWrapper completionCallback) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String getName() throws android.os.RemoteException
    {
      return null;
    }
    @Override public void setDownloadDirectory(java.lang.String directory) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.weblayer_private.interfaces.IProfile
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.weblayer_private.interfaces.IProfile";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.weblayer_private.interfaces.IProfile interface,
     * generating a proxy if needed.
     */
    public static org.chromium.weblayer_private.interfaces.IProfile asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.weblayer_private.interfaces.IProfile))) {
        return ((org.chromium.weblayer_private.interfaces.IProfile)iin);
      }
      return new org.chromium.weblayer_private.interfaces.IProfile.Stub.Proxy(obj);
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
        case TRANSACTION_destroy:
        {
          data.enforceInterface(descriptor);
          this.destroy();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_clearBrowsingData:
        {
          data.enforceInterface(descriptor);
          int[] _arg0;
          _arg0 = data.createIntArray();
          long _arg1;
          _arg1 = data.readLong();
          long _arg2;
          _arg2 = data.readLong();
          org.chromium.weblayer_private.interfaces.IObjectWrapper _arg3;
          _arg3 = org.chromium.weblayer_private.interfaces.IObjectWrapper.Stub.asInterface(data.readStrongBinder());
          this.clearBrowsingData(_arg0, _arg1, _arg2, _arg3);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getName:
        {
          data.enforceInterface(descriptor);
          java.lang.String _result = this.getName();
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        case TRANSACTION_setDownloadDirectory:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.setDownloadDirectory(_arg0);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.weblayer_private.interfaces.IProfile
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
      @Override public void destroy() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_destroy, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().destroy();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void clearBrowsingData(int[] dataTypes, long fromMillis, long toMillis, org.chromium.weblayer_private.interfaces.IObjectWrapper completionCallback) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeIntArray(dataTypes);
          _data.writeLong(fromMillis);
          _data.writeLong(toMillis);
          _data.writeStrongBinder((((completionCallback!=null))?(completionCallback.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_clearBrowsingData, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().clearBrowsingData(dataTypes, fromMillis, toMillis, completionCallback);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String getName() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getName, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getName();
          }
          _reply.readException();
          _result = _reply.readString();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void setDownloadDirectory(java.lang.String directory) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(directory);
          boolean _status = mRemote.transact(Stub.TRANSACTION_setDownloadDirectory, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setDownloadDirectory(directory);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      public static org.chromium.weblayer_private.interfaces.IProfile sDefaultImpl;
    }
    static final int TRANSACTION_destroy = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_clearBrowsingData = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_getName = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_setDownloadDirectory = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    public static boolean setDefaultImpl(org.chromium.weblayer_private.interfaces.IProfile impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.weblayer_private.interfaces.IProfile getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public void destroy() throws android.os.RemoteException;
  public void clearBrowsingData(int[] dataTypes, long fromMillis, long toMillis, org.chromium.weblayer_private.interfaces.IObjectWrapper completionCallback) throws android.os.RemoteException;
  public java.lang.String getName() throws android.os.RemoteException;
  public void setDownloadDirectory(java.lang.String directory) throws android.os.RemoteException;
}
