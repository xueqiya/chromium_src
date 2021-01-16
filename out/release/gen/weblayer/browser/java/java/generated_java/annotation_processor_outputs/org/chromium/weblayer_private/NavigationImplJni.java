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
final class NavigationImplJni implements NavigationImpl.Natives {
  private static NavigationImpl.Natives testInstance;

  public static final JniStaticTestMocker<NavigationImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.NavigationImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.weblayer_private.NavigationImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public void setJavaNavigation(long nativeNavigationImpl, NavigationImpl caller) {
    N.MAxzZ9OU(nativeNavigationImpl, caller);
  }

  @Override
  public int getState(long nativeNavigationImpl, NavigationImpl caller) {
    return (int)N.MOjYwlCQ(nativeNavigationImpl, caller);
  }

  @Override
  public String getUri(long nativeNavigationImpl, NavigationImpl caller) {
    return (String)N.MLe5UH8x(nativeNavigationImpl, caller);
  }

  @Override
  public String[] getRedirectChain(long nativeNavigationImpl, NavigationImpl caller) {
    return (String[])N.M4$r2b34(nativeNavigationImpl, caller);
  }

  @Override
  public int getHttpStatusCode(long nativeNavigationImpl, NavigationImpl caller) {
    return (int)N.MavL_hzo(nativeNavigationImpl, caller);
  }

  @Override
  public boolean isSameDocument(long nativeNavigationImpl, NavigationImpl caller) {
    return (boolean)N.MNvdMHI6(nativeNavigationImpl, caller);
  }

  @Override
  public boolean isErrorPage(long nativeNavigationImpl, NavigationImpl caller) {
    return (boolean)N.MIFgE7DZ(nativeNavigationImpl, caller);
  }

  @Override
  public int getLoadError(long nativeNavigationImpl, NavigationImpl caller) {
    return (int)N.Mu3sbx92(nativeNavigationImpl, caller);
  }

  public static NavigationImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.NavigationImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new NavigationImplJni();
  }
}
