package J;

import java.lang.Object;
import java.lang.String;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.policy.CombinedPolicyProvider.flushPolicies
   * @param nativeAndroidCombinedPolicyProvider (long)
   * @param caller (org.chromium.policy.CombinedPolicyProvider)
   * @return (void)
   */
  public static final native void M4QXUjg3(long nativeAndroidCombinedPolicyProvider, Object caller);

  /**
   * org.chromium.policy.PolicyConverter.setPolicyBoolean
   * @param nativePolicyConverter (long)
   * @param caller (org.chromium.policy.PolicyConverter)
   * @param policyKey (java.lang.String)
   * @param value (boolean)
   * @return (void)
   */
  public static final native void MpCbKnQi(long nativePolicyConverter, Object caller,
      String policyKey, boolean value);

  /**
   * org.chromium.policy.PolicyConverter.setPolicyInteger
   * @param nativePolicyConverter (long)
   * @param caller (org.chromium.policy.PolicyConverter)
   * @param policyKey (java.lang.String)
   * @param value (int)
   * @return (void)
   */
  public static final native void MTuFp9B7(long nativePolicyConverter, Object caller,
      String policyKey, int value);

  /**
   * org.chromium.policy.PolicyConverter.setPolicyString
   * @param nativePolicyConverter (long)
   * @param caller (org.chromium.policy.PolicyConverter)
   * @param policyKey (java.lang.String)
   * @param value (java.lang.String)
   * @return (void)
   */
  public static final native void MeuOZAup(long nativePolicyConverter, Object caller,
      String policyKey, String value);

  /**
   * org.chromium.policy.PolicyConverter.setPolicyStringArray
   * @param nativePolicyConverter (long)
   * @param caller (org.chromium.policy.PolicyConverter)
   * @param policyKey (java.lang.String)
   * @param value (java.lang.String[])
   * @return (void)
   */
  public static final native void MGY2QXB9(long nativePolicyConverter, Object caller,
      String policyKey, String[] value);
}
