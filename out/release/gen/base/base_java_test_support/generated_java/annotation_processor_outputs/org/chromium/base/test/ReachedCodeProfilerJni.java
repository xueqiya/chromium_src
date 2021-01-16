package org.chromium.base.test;

import J.N;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class ReachedCodeProfilerJni implements ReachedCodeProfiler.Natives {
  private static ReachedCodeProfiler.Natives testInstance;

  public static final JniStaticTestMocker<ReachedCodeProfiler.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.base.test.ReachedCodeProfiler.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.base.test.ReachedCodeProfiler.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public boolean isReachedCodeProfilerEnabled() {
    return (boolean)N.MAvd5yDU();
  }

  @Override
  public boolean isReachedCodeProfilerSupported() {
    return (boolean)N.MbYaLxm7();
  }

  public static ReachedCodeProfiler.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.base.test.ReachedCodeProfiler.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new ReachedCodeProfilerJni();
  }
}
