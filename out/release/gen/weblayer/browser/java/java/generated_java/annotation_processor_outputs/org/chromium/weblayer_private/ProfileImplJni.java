package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import java.lang.Runnable;
import java.lang.String;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class ProfileImplJni implements ProfileImpl.Natives {
  private static ProfileImpl.Natives testInstance;

  public static final JniStaticTestMocker<ProfileImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.ProfileImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.weblayer_private.ProfileImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createProfile(String name) {
    return (long)N.MKGVVWNd(name);
  }

  @Override
  public void deleteProfile(long profile) {
    N.M_1y2G80(profile);
  }

  @Override
  public void clearBrowsingData(long nativeProfileImpl, int[] dataTypes, long fromMillis,
      long toMillis, Runnable callback) {
    N.MTR7prkl(nativeProfileImpl, dataTypes, fromMillis, toMillis, callback);
  }

  @Override
  public void setDownloadDirectory(long nativeProfileImpl, String directory) {
    N.Mq7GFTAG(nativeProfileImpl, directory);
  }

  public static ProfileImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.ProfileImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new ProfileImplJni();
  }
}
