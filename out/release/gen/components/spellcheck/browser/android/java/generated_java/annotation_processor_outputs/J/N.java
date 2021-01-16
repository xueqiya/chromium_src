package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.components.spellcheck.SpellCheckerSessionBridge.processSpellCheckResults
   * @param nativeSpellCheckerSessionBridge (long)
   * @param caller (org.chromium.components.spellcheck.SpellCheckerSessionBridge)
   * @param offsets (int[])
   * @param lengths (int[])
   * @param suggestions (java.lang.String[][])
   * @return (void)
   */
  public static final native void M3JV9hBl(long nativeSpellCheckerSessionBridge, Object caller,
      int[] offsets, int[] lengths, String[][] suggestions);
}
