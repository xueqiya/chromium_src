package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class DownloadCallbackProxyJni implements DownloadCallbackProxy.Natives {
  private static DownloadCallbackProxy.Natives testInstance;

  public static final JniStaticTestMocker<DownloadCallbackProxy.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.DownloadCallbackProxy.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.weblayer_private.DownloadCallbackProxy.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createDownloadCallbackProxy(DownloadCallbackProxy proxy, long tab) {
    return (long)N.McPAi5G9(proxy, tab);
  }

  @Override
  public void deleteDownloadCallbackProxy(long proxy) {
    N.Mq3U77nO(proxy);
  }

  @Override
  public void allowDownload(long callbackId, boolean allow) {
    N.MYOOvdZV(callbackId, allow);
  }

  public static DownloadCallbackProxy.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.DownloadCallbackProxy.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new DownloadCallbackProxyJni();
  }
}
