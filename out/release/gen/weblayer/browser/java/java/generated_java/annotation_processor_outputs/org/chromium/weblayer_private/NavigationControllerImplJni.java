package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import java.lang.String;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class NavigationControllerImplJni implements NavigationControllerImpl.Natives {
  private static NavigationControllerImpl.Natives testInstance;

  public static final JniStaticTestMocker<NavigationControllerImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.NavigationControllerImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.weblayer_private.NavigationControllerImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public void setNavigationControllerImpl(long nativeNavigationControllerImpl,
      NavigationControllerImpl caller) {
    N.MpejyhKI(nativeNavigationControllerImpl, caller);
  }

  @Override
  public long getNavigationController(long tab) {
    return (long)N.MuaFsixb(tab);
  }

  @Override
  public void navigate(long nativeNavigationControllerImpl, NavigationControllerImpl caller,
      String uri) {
    N.MdNsGAMH(nativeNavigationControllerImpl, caller, uri);
  }

  @Override
  public void goBack(long nativeNavigationControllerImpl, NavigationControllerImpl caller) {
    N.MZrOkH8X(nativeNavigationControllerImpl, caller);
  }

  @Override
  public void goForward(long nativeNavigationControllerImpl, NavigationControllerImpl caller) {
    N.MDkifRYV(nativeNavigationControllerImpl, caller);
  }

  @Override
  public boolean canGoBack(long nativeNavigationControllerImpl, NavigationControllerImpl caller) {
    return (boolean)N.Mk5Op77A(nativeNavigationControllerImpl, caller);
  }

  @Override
  public boolean canGoForward(long nativeNavigationControllerImpl,
      NavigationControllerImpl caller) {
    return (boolean)N.Myt080DX(nativeNavigationControllerImpl, caller);
  }

  @Override
  public void goToIndex(long nativeNavigationControllerImpl, NavigationControllerImpl caller,
      int index) {
    N.M0Oi$rdJ(nativeNavigationControllerImpl, caller, index);
  }

  @Override
  public void reload(long nativeNavigationControllerImpl, NavigationControllerImpl caller) {
    N.MgCpZ61D(nativeNavigationControllerImpl, caller);
  }

  @Override
  public void stop(long nativeNavigationControllerImpl, NavigationControllerImpl caller) {
    N.Mcpd2RLR(nativeNavigationControllerImpl, caller);
  }

  @Override
  public int getNavigationListSize(long nativeNavigationControllerImpl,
      NavigationControllerImpl caller) {
    return (int)N.MTQXD9PA(nativeNavigationControllerImpl, caller);
  }

  @Override
  public int getNavigationListCurrentIndex(long nativeNavigationControllerImpl,
      NavigationControllerImpl caller) {
    return (int)N.MYvsya1k(nativeNavigationControllerImpl, caller);
  }

  @Override
  public String getNavigationEntryDisplayUri(long nativeNavigationControllerImpl,
      NavigationControllerImpl caller, int index) {
    return (String)N.MdarrSGz(nativeNavigationControllerImpl, caller, index);
  }

  @Override
  public String getNavigationEntryTitle(long nativeNavigationControllerImpl,
      NavigationControllerImpl caller, int index) {
    return (String)N.ME_QUEJm(nativeNavigationControllerImpl, caller, index);
  }

  public static NavigationControllerImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.NavigationControllerImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new NavigationControllerImplJni();
  }
}
