package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import java.lang.String;
import javax.annotation.Generated;
import org.chromium.base.Callback;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;
import org.chromium.components.autofill.AutofillProvider;
import org.chromium.content_public.browser.WebContents;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class TabImplJni implements TabImpl.Natives {
  private static TabImpl.Natives testInstance;

  public static final JniStaticTestMocker<TabImpl.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.TabImpl.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(org.chromium.weblayer_private.TabImpl.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createTab(long profile, TabImpl caller) {
    return (long)N.M0NNPeB3(profile, caller);
  }

  @Override
  public void setJavaImpl(long nativeTabImpl, TabImpl impl) {
    N.MKSJ4vB6(nativeTabImpl, impl);
  }

  @Override
  public void onAutofillProviderChanged(long nativeTabImpl, AutofillProvider autofillProvider) {
    N.Myi236il(nativeTabImpl, autofillProvider);
  }

  @Override
  public void setTopControlsContainerView(long nativeTabImpl, TabImpl caller,
      long nativeTopControlsContainerView) {
    N.Mdvft$Wr(nativeTabImpl, caller, nativeTopControlsContainerView);
  }

  @Override
  public void deleteTab(long tab) {
    N.MD18T2Ck(tab);
  }

  @Override
  public WebContents getWebContents(long nativeTabImpl, TabImpl caller) {
    return (WebContents)N.MV_K4t5p(nativeTabImpl, caller);
  }

  @Override
  public void executeScript(long nativeTabImpl, String script, boolean useSeparateIsolate,
      Callback<String> callback) {
    N.M9gymlSj(nativeTabImpl, script, useSeparateIsolate, callback);
  }

  public static TabImpl.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.TabImpl.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new TabImplJni();
  }
}
