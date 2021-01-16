package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class NewTabCallbackProxyJni implements NewTabCallbackProxy.Natives {
  private static NewTabCallbackProxy.Natives testInstance;

  public static final JniStaticTestMocker<NewTabCallbackProxy.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.NewTabCallbackProxy.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.weblayer_private.NewTabCallbackProxy.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createNewTabCallbackProxy(NewTabCallbackProxy proxy, long tab) {
    return (long)N.Mm1ByG3d(proxy, tab);
  }

  @Override
  public void deleteNewTabCallbackProxy(long proxy) {
    N.MxkBiJzp(proxy);
  }

  public static NewTabCallbackProxy.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.NewTabCallbackProxy.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new NewTabCallbackProxyJni();
  }
}
