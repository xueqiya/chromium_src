package org.chromium.weblayer_private;

import J.N;
import android.view.Surface;
import java.lang.Override;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;
import org.chromium.content_public.browser.WebContents;
import org.chromium.ui.base.WindowAndroid;
import org.chromium.ui.resources.ResourceManager;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class ContentViewRenderViewJni implements ContentViewRenderView.Natives {
  private static ContentViewRenderView.Natives testInstance;

  public static final JniStaticTestMocker<ContentViewRenderView.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.weblayer_private.ContentViewRenderView.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.weblayer_private.ContentViewRenderView.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long init(ContentViewRenderView caller, WindowAndroid rootWindow) {
    return (long)N.MuuxVGQm(caller, rootWindow);
  }

  @Override
  public void destroy(long nativeContentViewRenderView) {
    N.MAIaE0OG(nativeContentViewRenderView);
  }

  @Override
  public void setCurrentWebContents(long nativeContentViewRenderView, WebContents webContents) {
    N.MYMjn0mf(nativeContentViewRenderView, webContents);
  }

  @Override
  public void onPhysicalBackingSizeChanged(long nativeContentViewRenderView,
      WebContents webContents, int width, int height) {
    N.MQtCkWmJ(nativeContentViewRenderView, webContents, width, height);
  }

  @Override
  public void surfaceCreated(long nativeContentViewRenderView) {
    N.MUdnoeZS(nativeContentViewRenderView);
  }

  @Override
  public void surfaceDestroyed(long nativeContentViewRenderView, boolean cacheBackBuffer) {
    N.MfxYKOP7(nativeContentViewRenderView, cacheBackBuffer);
  }

  @Override
  public void surfaceChanged(long nativeContentViewRenderView, boolean canBeUsedWithSurfaceControl,
      int format, int width, int height, Surface surface) {
    N.M4g6Q4ab(nativeContentViewRenderView, canBeUsedWithSurfaceControl, format, width, height, surface);
  }

  @Override
  public void evictCachedSurface(long nativeContentViewRenderView) {
    N.M9bR5p1w(nativeContentViewRenderView);
  }

  @Override
  public ResourceManager getResourceManager(long nativeContentViewRenderView) {
    return (ResourceManager)N.M7ewD88L(nativeContentViewRenderView);
  }

  public static ContentViewRenderView.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.weblayer_private.ContentViewRenderView.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new ContentViewRenderViewJni();
  }
}
