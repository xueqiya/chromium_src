/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.weblayer_private.interfaces;
public interface ITab extends android.os.IInterface
{
  /** Default implementation for ITab. */
  public static class Default implements org.chromium.weblayer_private.interfaces.ITab
  {
    @Override public void setClient(org.chromium.weblayer_private.interfaces.ITabClient client) throws android.os.RemoteException
    {
    }
    @Override public org.chromium.weblayer_private.interfaces.INavigationController createNavigationController(org.chromium.weblayer_private.interfaces.INavigationControllerClient client) throws android.os.RemoteException
    {
      return null;
    }
    @Override public void setDownloadCallbackClient(org.chromium.weblayer_private.interfaces.IDownloadCallbackClient client) throws android.os.RemoteException
    {
    }
    @Override public void setErrorPageCallbackClient(org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient client) throws android.os.RemoteException
    {
    }
    @Override public void setFullscreenCallbackClient(org.chromium.weblayer_private.interfaces.IFullscreenCallbackClient client) throws android.os.RemoteException
    {
    }
    @Override public void executeScript(java.lang.String script, boolean useSeparateIsolate, org.chromium.weblayer_private.interfaces.IObjectWrapper callback) throws android.os.RemoteException
    {
    }
    @Override public void setNewTabsEnabled(boolean enabled) throws android.os.RemoteException
    {
    }
    // Returns a unique identifier for this Tab. The id is *not* unique across
    // restores. The id is intended for the client library to avoid creating duplicate client objects
    // for the same ITab.

    @Override public int getId() throws android.os.RemoteException
    {
      return 0;
    }
    @Override public boolean setFindInPageCallbackClient(org.chromium.weblayer_private.interfaces.IFindInPageCallbackClient client) throws android.os.RemoteException
    {
      return false;
    }
    @Override public void findInPage(java.lang.String searchText, boolean forward) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.weblayer_private.interfaces.ITab
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.weblayer_private.interfaces.ITab";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.weblayer_private.interfaces.ITab interface,
     * generating a proxy if needed.
     */
    public static org.chromium.weblayer_private.interfaces.ITab asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.weblayer_private.interfaces.ITab))) {
        return ((org.chromium.weblayer_private.interfaces.ITab)iin);
      }
      return new org.chromium.weblayer_private.interfaces.ITab.Stub.Proxy(obj);
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
        case TRANSACTION_setClient:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.ITabClient _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.ITabClient.Stub.asInterface(data.readStrongBinder());
          this.setClient(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_createNavigationController:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.INavigationControllerClient _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.INavigationControllerClient.Stub.asInterface(data.readStrongBinder());
          org.chromium.weblayer_private.interfaces.INavigationController _result = this.createNavigationController(_arg0);
          reply.writeNoException();
          reply.writeStrongBinder((((_result!=null))?(_result.asBinder()):(null)));
          return true;
        }
        case TRANSACTION_setDownloadCallbackClient:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.IDownloadCallbackClient _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.IDownloadCallbackClient.Stub.asInterface(data.readStrongBinder());
          this.setDownloadCallbackClient(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setErrorPageCallbackClient:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient.Stub.asInterface(data.readStrongBinder());
          this.setErrorPageCallbackClient(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setFullscreenCallbackClient:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.IFullscreenCallbackClient _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.IFullscreenCallbackClient.Stub.asInterface(data.readStrongBinder());
          this.setFullscreenCallbackClient(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_executeScript:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          org.chromium.weblayer_private.interfaces.IObjectWrapper _arg2;
          _arg2 = org.chromium.weblayer_private.interfaces.IObjectWrapper.Stub.asInterface(data.readStrongBinder());
          this.executeScript(_arg0, _arg1, _arg2);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_setNewTabsEnabled:
        {
          data.enforceInterface(descriptor);
          boolean _arg0;
          _arg0 = (0!=data.readInt());
          this.setNewTabsEnabled(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getId:
        {
          data.enforceInterface(descriptor);
          int _result = this.getId();
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_setFindInPageCallbackClient:
        {
          data.enforceInterface(descriptor);
          org.chromium.weblayer_private.interfaces.IFindInPageCallbackClient _arg0;
          _arg0 = org.chromium.weblayer_private.interfaces.IFindInPageCallbackClient.Stub.asInterface(data.readStrongBinder());
          boolean _result = this.setFindInPageCallbackClient(_arg0);
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_findInPage:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          boolean _arg1;
          _arg1 = (0!=data.readInt());
          this.findInPage(_arg0, _arg1);
          reply.writeNoException();
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.weblayer_private.interfaces.ITab
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
      @Override public void setClient(org.chromium.weblayer_private.interfaces.ITabClient client) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((client!=null))?(client.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setClient, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setClient(client);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public org.chromium.weblayer_private.interfaces.INavigationController createNavigationController(org.chromium.weblayer_private.interfaces.INavigationControllerClient client) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        org.chromium.weblayer_private.interfaces.INavigationController _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((client!=null))?(client.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_createNavigationController, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().createNavigationController(client);
          }
          _reply.readException();
          _result = org.chromium.weblayer_private.interfaces.INavigationController.Stub.asInterface(_reply.readStrongBinder());
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public void setDownloadCallbackClient(org.chromium.weblayer_private.interfaces.IDownloadCallbackClient client) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((client!=null))?(client.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setDownloadCallbackClient, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setDownloadCallbackClient(client);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setErrorPageCallbackClient(org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient client) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((client!=null))?(client.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setErrorPageCallbackClient, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setErrorPageCallbackClient(client);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setFullscreenCallbackClient(org.chromium.weblayer_private.interfaces.IFullscreenCallbackClient client) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((client!=null))?(client.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setFullscreenCallbackClient, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setFullscreenCallbackClient(client);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void executeScript(java.lang.String script, boolean useSeparateIsolate, org.chromium.weblayer_private.interfaces.IObjectWrapper callback) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(script);
          _data.writeInt(((useSeparateIsolate)?(1):(0)));
          _data.writeStrongBinder((((callback!=null))?(callback.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_executeScript, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().executeScript(script, useSeparateIsolate, callback);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void setNewTabsEnabled(boolean enabled) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(((enabled)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setNewTabsEnabled, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().setNewTabsEnabled(enabled);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      // Returns a unique identifier for this Tab. The id is *not* unique across
      // restores. The id is intended for the client library to avoid creating duplicate client objects
      // for the same ITab.

      @Override public int getId() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getId, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getId();
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      @Override public boolean setFindInPageCallbackClient(org.chromium.weblayer_private.interfaces.IFindInPageCallbackClient client) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeStrongBinder((((client!=null))?(client.asBinder()):(null)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_setFindInPageCallbackClient, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().setFindInPageCallbackClient(client);
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
      @Override public void findInPage(java.lang.String searchText, boolean forward) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(searchText);
          _data.writeInt(((forward)?(1):(0)));
          boolean _status = mRemote.transact(Stub.TRANSACTION_findInPage, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().findInPage(searchText, forward);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      public static org.chromium.weblayer_private.interfaces.ITab sDefaultImpl;
    }
    static final int TRANSACTION_setClient = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_createNavigationController = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_setDownloadCallbackClient = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_setErrorPageCallbackClient = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_setFullscreenCallbackClient = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_executeScript = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_setNewTabsEnabled = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getId = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_setFindInPageCallbackClient = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_findInPage = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    public static boolean setDefaultImpl(org.chromium.weblayer_private.interfaces.ITab impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.weblayer_private.interfaces.ITab getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public void setClient(org.chromium.weblayer_private.interfaces.ITabClient client) throws android.os.RemoteException;
  public org.chromium.weblayer_private.interfaces.INavigationController createNavigationController(org.chromium.weblayer_private.interfaces.INavigationControllerClient client) throws android.os.RemoteException;
  public void setDownloadCallbackClient(org.chromium.weblayer_private.interfaces.IDownloadCallbackClient client) throws android.os.RemoteException;
  public void setErrorPageCallbackClient(org.chromium.weblayer_private.interfaces.IErrorPageCallbackClient client) throws android.os.RemoteException;
  public void setFullscreenCallbackClient(org.chromium.weblayer_private.interfaces.IFullscreenCallbackClient client) throws android.os.RemoteException;
  public void executeScript(java.lang.String script, boolean useSeparateIsolate, org.chromium.weblayer_private.interfaces.IObjectWrapper callback) throws android.os.RemoteException;
  public void setNewTabsEnabled(boolean enabled) throws android.os.RemoteException;
  // Returns a unique identifier for this Tab. The id is *not* unique across
  // restores. The id is intended for the client library to avoid creating duplicate client objects
  // for the same ITab.

  public int getId() throws android.os.RemoteException;
  public boolean setFindInPageCallbackClient(org.chromium.weblayer_private.interfaces.IFindInPageCallbackClient client) throws android.os.RemoteException;
  public void findInPage(java.lang.String searchText, boolean forward) throws android.os.RemoteException;
}
