package org.chromium.components.find_in_page;

import J.N;
import java.lang.Override;
import java.lang.String;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;
import org.chromium.content_public.browser.WebContents;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class FindInPageBridgeJni implements FindInPageBridge.Natives {
  private static FindInPageBridge.Natives testInstance;

  public static final JniStaticTestMocker<FindInPageBridge.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.components.find_in_page.FindInPageBridge.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.components.find_in_page.FindInPageBridge.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public long init(FindInPageBridge caller, WebContents webContents) {
    return (long)N.MW6nK$q1(caller, webContents);
  }

  @Override
  public void destroy(long nativeFindInPageBridge, FindInPageBridge caller) {
    N.MlPioXlo(nativeFindInPageBridge, caller);
  }

  @Override
  public void startFinding(long nativeFindInPageBridge, FindInPageBridge caller,
      String searchString, boolean forwardDirection, boolean caseSensitive) {
    N.MiKuFRTN(nativeFindInPageBridge, caller, searchString, forwardDirection, caseSensitive);
  }

  @Override
  public void stopFinding(long nativeFindInPageBridge, FindInPageBridge caller,
      boolean clearSelection) {
    N.MWOuMqhA(nativeFindInPageBridge, caller, clearSelection);
  }

  @Override
  public String getPreviousFindText(long nativeFindInPageBridge, FindInPageBridge caller) {
    return (String)N.M3t_h9OB(nativeFindInPageBridge, caller);
  }

  @Override
  public void requestFindMatchRects(long nativeFindInPageBridge, FindInPageBridge caller,
      int currentVersion) {
    N.M4m8QCn$(nativeFindInPageBridge, caller, currentVersion);
  }

  @Override
  public void activateNearestFindResult(long nativeFindInPageBridge, FindInPageBridge caller,
      float x, float y) {
    N.MqpwqIAC(nativeFindInPageBridge, caller, x, y);
  }

  @Override
  public void activateFindInPageResultForAccessibility(long nativeFindInPageBridge,
      FindInPageBridge caller) {
    N.MNC06_Rq(nativeFindInPageBridge, caller);
  }

  public static FindInPageBridge.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.components.find_in_page.FindInPageBridge.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new FindInPageBridgeJni();
  }
}
