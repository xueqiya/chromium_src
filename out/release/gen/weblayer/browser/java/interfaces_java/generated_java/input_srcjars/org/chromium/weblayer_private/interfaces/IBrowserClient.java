/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.weblayer_private.interfaces;
public interface IBrowserClient extends android.os.IInterface
{
  /** Default implementation for IBrowserClient. */
  public static class Default implements org.chromium.weblayer_private.interfaces.IBrowserClient
  {
    @Override public void onActiveTabChanged(int activeTabId) throws android.os.RemoteException
    {
    }
    @Override public void onTabAdded(org.chromium.weblayer_private.interfaces.ITab tab) throws android.os.RemoteException
    {
    }
    @Override public void onTabRemoved(int tabId) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.weblayer_private.interfaces.IBrowserClient
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.weblayer_private.interfaces.IBrowserClient";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.weblayer_private.interfaces.IBrowserClient interface,
     * generating a proxy if needed.
     */
    public static org.chromium.weblayer_private.interfaces.IBrowserClient asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.weblayer_private.interfaces.IBrowserClient))) {
        return ((org.chromium.weblayer_private.interfaces.IBrowserClient)iin);
      }
      return new org.chromium.weblayer_private.interfaces.IBrowserClient.Stub.Proxy(obj);
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
        case TRANSACTION_onActiveTabChanged:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.onActiveTabChanged(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onTabAdded:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.ITab _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.ITab.Stub.asInterface(data.readStrongBinder());
          this.onTabAdded(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onTabRemoved:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.onTabRemoved(_arg0);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.weblayer_private.interfaces.IBrowserClient
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
      @Override public void onActiveTabChanged(int activeTabId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(activeTabId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onActiveTabChanged, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onActiveTabChanged(activeTabId);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onTabAdded(org.chromium.weblayer_private.interfaces.ITab tab) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((tab!=null))?(tab.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_onTabAdded, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onTabAdded(tab);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onTabRemoved(int tabId) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(tabId);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onTabRemoved, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onTabRemoved(tabId);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      public static org.chromium.weblayer_private.interfaces.IBrowserClient sDefaultImpl;
    }
    static final int TRANSACTION_onActiveTabChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onTabAdded = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onTabRemoved = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    public static boolean setDefaultImpl(org.chromium.weblayer_private.interfaces.IBrowserClient impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.weblayer_private.interfaces.IBrowserClient getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public void onActiveTabChanged(int activeTabId) throws android.os.RemoteException;
  public void onTabAdded(org.chromium.weblayer_private.interfaces.ITab tab) throws android.os.RemoteException;
  public void onTabRemoved(int tabId) throws android.os.RemoteException;
}
