package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class FullscreenCallbackProxyJni implements FullscreenCallbackProxy.Natives {
  private static FullscreenCallbackProxy.Natives testInstance;

  public static final JniStaticTestMocker<FullscreenCallbackProxy.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.FullscreenCallbackProxy.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.weblayer_private.FullscreenCallbackProxy.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createFullscreenCallbackProxy(FullscreenCallbackProxy proxy, long tab) {
    return (long)N.MGmykU1g(proxy, tab);
  }

  @Override
  public void deleteFullscreenCallbackProxy(long proxy) {
    N.MeleUM$n(proxy);
  }

  @Override
  public void doExitFullscreen(long nativeFullscreenCallbackProxy, FullscreenCallbackProxy proxy) {
    N.MSOA10zg(nativeFullscreenCallbackProxy, proxy);
  }

  public static FullscreenCallbackProxy.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.FullscreenCallbackProxy.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new FullscreenCallbackProxyJni();
  }
}
