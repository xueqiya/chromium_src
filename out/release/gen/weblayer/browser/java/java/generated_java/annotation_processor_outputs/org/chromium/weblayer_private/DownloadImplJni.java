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
final class DownloadImplJni implements DownloadImpl.Natives {
  private static DownloadImpl.Natives testInstance;

  public static final JniStaticTestMocker<DownloadImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.DownloadImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.weblayer_private.DownloadImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public void setJavaDownload(long nativeDownloadImpl, DownloadImpl caller) {
    N.MCQjxfAX(nativeDownloadImpl, caller);
  }

  @Override
  public int getState(long nativeDownloadImpl, DownloadImpl caller) {
    return (int)N.Mg9vWlA3(nativeDownloadImpl, caller);
  }

  @Override
  public long getTotalBytes(long nativeDownloadImpl, DownloadImpl caller) {
    return (long)N.MLQnpV49(nativeDownloadImpl, caller);
  }

  @Override
  public long getReceivedBytes(long nativeDownloadImpl, DownloadImpl caller) {
    return (long)N.MLPJbQwI(nativeDownloadImpl, caller);
  }

  @Override
  public void pause(long nativeDownloadImpl, DownloadImpl caller) {
    N.Mmh9t8Wp(nativeDownloadImpl, caller);
  }

  @Override
  public void resume(long nativeDownloadImpl, DownloadImpl caller) {
    N.MBdFHh_o(nativeDownloadImpl, caller);
  }

  @Override
  public void cancel(long nativeDownloadImpl, DownloadImpl caller) {
    N.M7ycbCea(nativeDownloadImpl, caller);
  }

  @Override
  public String getLocation(long nativeDownloadImpl, DownloadImpl caller) {
    return (String)N.MBNW0Bg1(nativeDownloadImpl, caller);
  }

  @Override
  public String getMimeTypeImpl(long nativeDownloadImpl, DownloadImpl caller) {
    return (String)N.MiYZ62wR(nativeDownloadImpl, caller);
  }

  @Override
  public int getError(long nativeDownloadImpl, DownloadImpl caller) {
    return (int)N.MMo$maOT(nativeDownloadImpl, caller);
  }

  public static DownloadImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.DownloadImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new DownloadImplJni();
  }
}
