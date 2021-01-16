package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class WebLayerImplJni implements WebLayerImpl.Natives {
  private static WebLayerImpl.Natives testInstance;

  public static final JniStaticTestMocker<WebLayerImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.WebLayerImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.weblayer_private.WebLayerImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public void setRemoteDebuggingEnabled(boolean enabled) {
    N.M1lGn20V(enabled);
  }

  @Override
  public boolean isRemoteDebuggingEnabled() {
    return (boolean)N.MdEjk1wX();
  }

  @Override
  public void setIsWebViewCompatMode(boolean value) {
    N.MVSxAa8H(value);
  }

  public static WebLayerImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.WebLayerImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new WebLayerImplJni();
  }
}
