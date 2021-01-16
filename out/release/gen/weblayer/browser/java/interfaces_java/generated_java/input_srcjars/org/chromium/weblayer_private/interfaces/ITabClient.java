/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.weblayer_private.interfaces;
/**
 * Interface used by Tab to inform the client of changes. This largely duplicates the
 * TabCallback interface, but is a singleton to avoid unnecessary IPC.
 */
public interface ITabClient extends android.os.IInterface
{
  /** Default implementation for ITabClient. */
  public static class Default implements org.chromium.weblayer_private.interfaces.ITabClient
  {
    @Override public void visibleUriChanged(java.lang.String uriString) throws android.os.RemoteException
    {
    }
    @Override public void onNewTab(int tabId, int mode) throws android.os.RemoteException
    {
    }
    @Override public void onRenderProcessGone() throws android.os.RemoteException
    {
    }
    @Override public void onCloseTab() throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.weblayer_private.interfaces.ITabClient
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.weblayer_private.interfaces.ITabClient";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.weblayer_private.interfaces.ITabClient interface,
     * generating a proxy if needed.
     */
    public static org.chromium.weblayer_private.interfaces.ITabClient asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.weblayer_private.interfaces.ITabClient))) {
        return ((org.chromium.weblayer_private.interfaces.ITabClient)iin);
      }
      return new org.chromium.weblayer_private.interfaces.ITabClient.Stub.Proxy(obj);
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
        case TRANSACTION_visibleUriChanged:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.visibleUriChanged(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onNewTab:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          this.onNewTab(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onRenderProcessGone:
        {
          data.enforceInterface(descriptor);
          this.onRenderProcessGone();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_onCloseTab:
        {
          data.enforceInterface(descriptor);
          this.onCloseTab();
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.weblayer_private.interfaces.ITabClient
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
      @Override public void visibleUriChanged(java.lang.String uriString) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(uriString);
          boolean _status = mRemote.transact(Stub.TRANSACTION_visibleUriChanged, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().visibleUriChanged(uriString);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onNewTab(int tabId, int mode) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(tabId);
          _data.writeInt(mode);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onNewTab, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onNewTab(tabId, mode);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onRenderProcessGone() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onRenderProcessGone, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onRenderProcessGone();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void onCloseTab() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onCloseTab, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onCloseTab();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      public static org.chromium.weblayer_private.interfaces.ITabClient sDefaultImpl;
    }
    static final int TRANSACTION_visibleUriChanged = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onNewTab = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_onRenderProcessGone = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_onCloseTab = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    public static boolean setDefaultImpl(org.chromium.weblayer_private.interfaces.ITabClient impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.weblayer_private.interfaces.ITabClient getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public void visibleUriChanged(java.lang.String uriString) throws android.os.RemoteException;
  public void onNewTab(int tabId, int mode) throws android.os.RemoteException;
  public void onRenderProcessGone() throws android.os.RemoteException;
  public void onCloseTab() throws android.os.RemoteException;
}
