package org.chromium.weblayer_private;

import J.N;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;
import org.chromium.content_public.browser.WebContents;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class TopControlsContainerViewJni implements TopControlsContainerView.Natives {
  private static TopControlsContainerView.Natives testInstance;

  public static final JniStaticTestMocker<TopControlsContainerView.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.TopControlsContainerView.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.weblayer_private.TopControlsContainerView.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long createTopControlsContainerView(TopControlsContainerView view,
      long nativeContentViewRenderView) {
    return (long)N.MxBee$83(view, nativeContentViewRenderView);
  }

  @Override
  public void deleteTopControlsContainerView(long nativeTopControlsContainerView,
      TopControlsContainerView caller) {
    N.MDsa1RkB(nativeTopControlsContainerView, caller);
  }

  @Override
  public void createTopControlsLayer(long nativeTopControlsContainerView,
      TopControlsContainerView caller, int id) {
    N.M_eicmWU(nativeTopControlsContainerView, caller, id);
  }

  @Override
  public void deleteTopControlsLayer(long nativeTopControlsContainerView,
      TopControlsContainerView caller) {
    N.M0ErzYW_(nativeTopControlsContainerView, caller);
  }

  @Override
  public void setTopControlsOffset(long nativeTopControlsContainerView,
      TopControlsContainerView caller, int topControlsOffsetY, int topContentOffsetY) {
    N.MSVvJOat(nativeTopControlsContainerView, caller, topControlsOffsetY, topContentOffsetY);
  }

  @Override
  public void setTopControlsSize(long nativeTopControlsContainerView,
      TopControlsContainerView caller, int width, int height) {
    N.M6kNhy4_(nativeTopControlsContainerView, caller, width, height);
  }

  @Override
  public void updateTopControlsResource(long nativeTopControlsContainerView,
      TopControlsContainerView caller) {
    N.Mxe_p5sj(nativeTopControlsContainerView, caller);
  }

  @Override
  public void setWebContents(long nativeTopControlsContainerView, TopControlsContainerView caller,
      WebContents webContents) {
    N.MAiLwgGG(nativeTopControlsContainerView, caller, webContents);
  }

  public static TopControlsContainerView.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.TopControlsContainerView.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new TopControlsContainerViewJni();
  }
}
