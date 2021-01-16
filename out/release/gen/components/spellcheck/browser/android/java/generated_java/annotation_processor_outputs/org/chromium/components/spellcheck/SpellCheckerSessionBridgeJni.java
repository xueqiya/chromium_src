package org.chromium.components.spellcheck;

import J.N;
import java.lang.Override;
import java.lang.String;
import javax.annotation.Generated;
import org.chromium.base.JniStaticTestMocker;
import org.chromium.base.NativeLibraryLoadedStatus;
import org.chromium.base.annotations.CheckDiscard;

@Generated("org.chromium.jni_generator.JniProcessor")
@CheckDiscard("crbug.com/993421")
final class SpellCheckerSessionBridgeJni implements SpellCheckerSessionBridge.Natives {
  private static SpellCheckerSessionBridge.Natives testInstance;

  public static final JniStaticTestMocker<SpellCheckerSessionBridge.Natives> TEST_HOOKS = new org.chromium.base.JniStaticTestMocker<org.chromium.components.spellcheck.SpellCheckerSessionBridge.Natives>() {
    @java.lang.Override
    public void setInstanceForTesting(
        org.chromium.components.spellcheck.SpellCheckerSessionBridge.Natives instance) {
      if (!J.N.TESTING_ENABLED) {
        throw new RuntimeException("Tried to set a JNI mock when mocks aren't enabled!");
      }
      testInstance = instance;
    }
  };

  @Override
  public void processSpellCheckResults(long nativeSpellCheckerSessionBridge,
      SpellCheckerSessionBridge caller, int[] offsets, int[] lengths, String[][] suggestions) {
    N.M3JV9hBl(nativeSpellCheckerSessionBridge, caller, offsets, lengths, suggestions);
  }

  public static SpellCheckerSessionBridge.Natives get() {
    if (N.TESTING_ENABLED) {
      if (testInstance != null) {
        return testInstance;
      }
      if (N.REQUIRE_MOCK) {
        throw new UnsupportedOperationException("No mock found for the native implementation for org.chromium.components.spellcheck.SpellCheckerSessionBridge.Natives. The current configuration requires all native implementations to have a mock instance.");
      }
    }
    NativeLibraryLoadedStatus.checkLoaded(false);
    return new SpellCheckerSessionBridgeJni();
  }
}
