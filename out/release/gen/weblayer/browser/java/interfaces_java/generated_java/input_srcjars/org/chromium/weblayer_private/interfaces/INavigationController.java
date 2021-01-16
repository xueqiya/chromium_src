/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package org.chromium.weblayer_private.interfaces;
public interface INavigationController extends android.os.IInterface
{
  /** Default implementation for INavigationController. */
  public static class Default implements org.chromium.weblayer_private.interfaces.INavigationController
  {
    @Override public void navigate(java.lang.String uri) throws android.os.RemoteException
    {
    }
    @Override public void goBack() throws android.os.RemoteException
    {
    }
    @Override public void goForward() throws android.os.RemoteException
    {
    }
    @Override public void reload() throws android.os.RemoteException
    {
    }
    @Override public void stop() throws android.os.RemoteException
    {
    }
    @Override public int getNavigationListSize() throws android.os.RemoteException
    {
      return 0;
    }
    @Override public int getNavigationListCurrentIndex() throws android.os.RemoteException
    {
      return 0;
    }
    @Override public java.lang.String getNavigationEntryDisplayUri(int index) throws android.os.RemoteException
    {
      return null;
    }
    @Override public boolean canGoBack() throws android.os.RemoteException
    {
      return false;
    }
    @Override public boolean canGoForward() throws android.os.RemoteException
    {
      return false;
    }
    @Override public void goToIndex(int index) throws android.os.RemoteException
    {
    }
    @Override public java.lang.String getNavigationEntryTitle(int index) throws android.os.RemoteException
    {
      return null;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements org.chromium.weblayer_private.interfaces.INavigationController
  {
    private static final java.lang.String DESCRIPTOR = "org.chromium.weblayer_private.interfaces.INavigationController";
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an org.chromium.weblayer_private.interfaces.INavigationController interface,
     * generating a proxy if needed.
     */
    public static org.chromium.weblayer_private.interfaces.INavigationController asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof org.chromium.weblayer_private.interfaces.INavigationController))) {
        return ((org.chromium.weblayer_private.interfaces.INavigationController)iin);
      }
      return new org.chromium.weblayer_private.interfaces.INavigationController.Stub.Proxy(obj);
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
        case TRANSACTION_navigate:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.navigate(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_goBack:
        {
          data.enforceInterface(descriptor);
          this.goBack();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_goForward:
        {
          data.enforceInterface(descriptor);
          this.goForward();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_reload:
        {
          data.enforceInterface(descriptor);
          this.reload();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_stop:
        {
          data.enforceInterface(descriptor);
          this.stop();
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getNavigationListSize:
        {
          data.enforceInterface(descriptor);
          int _result = this.getNavigationListSize();
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_getNavigationListCurrentIndex:
        {
          data.enforceInterface(descriptor);
          int _result = this.getNavigationListCurrentIndex();
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_getNavigationEntryDisplayUri:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _result = this.getNavigationEntryDisplayUri(_arg0);
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        case TRANSACTION_canGoBack:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.canGoBack();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_canGoForward:
        {
          data.enforceInterface(descriptor);
          boolean _result = this.canGoForward();
          reply.writeNoException();
          reply.writeInt(((_result)?(1):(0)));
          return true;
        }
        case TRANSACTION_goToIndex:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.goToIndex(_arg0);
          reply.writeNoException();
          return true;
        }
        case TRANSACTION_getNavigationEntryTitle:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          java.lang.String _result = this.getNavigationEntryTitle(_arg0);
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements org.chromium.weblayer_private.interfaces.INavigationController
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
      @Override public void navigate(java.lang.String uri) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(uri);
          boolean _status = mRemote.transact(Stub.TRANSACTION_navigate, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().navigate(uri);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void goBack() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_goBack, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().goBack();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void goForward() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_goForward, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().goForward();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void reload() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_reload, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().reload();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public void stop() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_stop, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().stop();
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public int getNavigationListSize() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getNavigationListSize, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getNavigationListSize();
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
      @Override public int getNavigationListCurrentIndex() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getNavigationListCurrentIndex, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getNavigationListCurrentIndex();
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
      @Override public java.lang.String getNavigationEntryDisplayUri(int index) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(index);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getNavigationEntryDisplayUri, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getNavigationEntryDisplayUri(index);
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
      @Override public boolean canGoBack() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_canGoBack, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().canGoBack();
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
      @Override public boolean canGoForward() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        boolean _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_canGoForward, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().canGoForward();
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
      @Override public void goToIndex(int index) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(index);
          boolean _status = mRemote.transact(Stub.TRANSACTION_goToIndex, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().goToIndex(index);
            return;
          }
          _reply.readException();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
      }
      @Override public java.lang.String getNavigationEntryTitle(int index) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(index);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getNavigationEntryTitle, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getNavigationEntryTitle(index);
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
      public static org.chromium.weblayer_private.interfaces.INavigationController sDefaultImpl;
    }
    static final int TRANSACTION_navigate = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_goBack = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_goForward = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_reload = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_stop = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    static final int TRANSACTION_getNavigationListSize = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
    static final int TRANSACTION_getNavigationListCurrentIndex = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
    static final int TRANSACTION_getNavigationEntryDisplayUri = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
    static final int TRANSACTION_canGoBack = (android.os.IBinder.FIRST_CALL_TRANSACTION + 8);
    static final int TRANSACTION_canGoForward = (android.os.IBinder.FIRST_CALL_TRANSACTION + 9);
    static final int TRANSACTION_goToIndex = (android.os.IBinder.FIRST_CALL_TRANSACTION + 10);
    static final int TRANSACTION_getNavigationEntryTitle = (android.os.IBinder.FIRST_CALL_TRANSACTION + 11);
    public static boolean setDefaultImpl(org.chromium.weblayer_private.interfaces.INavigationController impl) {
      if (Stub.Proxy.sDefaultImpl == null && impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static org.chromium.weblayer_private.interfaces.INavigationController getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  public void navigate(java.lang.String uri) throws android.os.RemoteException;
  public void goBack() throws android.os.RemoteException;
  public void goForward() throws android.os.RemoteException;
  public void reload() throws android.os.RemoteException;
  public void stop() throws android.os.RemoteException;
  public int getNavigationListSize() throws android.os.RemoteException;
  public int getNavigationListCurrentIndex() throws android.os.RemoteException;
  public java.lang.String getNavigationEntryDisplayUri(int index) throws android.os.RemoteException;
  public boolean canGoBack() throws android.os.RemoteException;
  public boolean canGoForward() throws android.os.RemoteException;
  public void goToIndex(int index) throws android.os.RemoteException;
  public java.lang.String getNavigationEntryTitle(int index) throws android.os.RemoteException;
}
