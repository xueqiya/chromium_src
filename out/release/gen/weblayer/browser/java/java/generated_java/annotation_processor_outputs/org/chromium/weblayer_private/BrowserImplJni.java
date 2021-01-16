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
final class BrowserImplJni implements BrowserImpl.Natives {
  private static BrowserImpl.Natives testInstance;

  public static final JniStaticTestMocker<BrowserImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.BrowserImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.weblayer_private.BrowserImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createBrowser(long profile, String persistenceId, byte[] persistenceCryptoKey,
      BrowserImpl caller) {
    return (long)N.MChsAOfs(profile, persistenceId, persistenceCryptoKey, caller);
  }

  @Override
  public void deleteBrowser(long browser) {
    N.MaMrnX9h(browser);
  }

  @Override
  public void addTab(long nativeBrowserImpl, BrowserImpl browser, long nativeTab) {
    N.MJ$RHdW5(nativeBrowserImpl, browser, nativeTab);
  }

  @Override
  public void removeTab(long nativeBrowserImpl, BrowserImpl browser, long nativeTab) {
    N.M2kEkJ8E(nativeBrowserImpl, browser, nativeTab);
  }

  @Override
  public TabImpl[] getTabs(long nativeBrowserImpl, BrowserImpl browser) {
    return (TabImpl[])N.MGDfuPeL(nativeBrowserImpl, browser);
  }

  @Override
  public void setActiveTab(long nativeBrowserImpl, BrowserImpl browser, long nativeTab) {
    N.MBT5EbFP(nativeBrowserImpl, browser, nativeTab);
  }

  @Override
  public TabImpl getActiveTab(long nativeBrowserImpl, BrowserImpl browser) {
    return (TabImpl)N.Ms4h$LOA(nativeBrowserImpl, browser);
  }

  @Override
  public void prepareForShutdown(long nativeBrowserImpl, BrowserImpl browser) {
    N.MM5Y8Vdi(nativeBrowserImpl, browser);
  }

  @Override
  public String getPersistenceId(long nativeBrowserImpl, BrowserImpl browser) {
    return (String)N.Mtk__Xyp(nativeBrowserImpl, browser);
  }

  @Override
  public void saveSessionServiceIfNecessary(long nativeBrowserImpl, BrowserImpl browser) {
    N.MzXbCRNG(nativeBrowserImpl, browser);
  }

  @Override
  public byte[] getSessionServiceCryptoKey(long nativeBrowserImpl, BrowserImpl browser) {
    return (byte[])N.M6R$gymF(nativeBrowserImpl, browser);
  }

  @Override
  public byte[] getMinimalPersistenceState(long nativeBrowserImpl, BrowserImpl browser) {
    return (byte[])N.MtZQkZrN(nativeBrowserImpl, browser);
  }

  public static BrowserImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.BrowserImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new BrowserImplJni();
  }
}
