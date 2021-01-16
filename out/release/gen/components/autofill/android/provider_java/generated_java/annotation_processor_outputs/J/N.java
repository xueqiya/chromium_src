package J;

import java.lang.Object;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.components.autofill.AutofillProvider.onAutofillAvailable
   * @param nativeAutofillProviderAndroid (long)
   * @param caller (org.chromium.components.autofill.AutofillProvider)
   * @param formData (org.chromium.components.autofill.FormData)
   * @return (void)
   */
  public static final native void MxVH2h8w(long nativeAutofillProviderAndroid, Object caller,
      Object formData);

  /**
   * org.chromium.components.autofill.FormData.getNextFormFieldData
   * @param nativeFormDataAndroid (long)
   * @param caller (org.chromium.components.autofill.FormData)
   * @return (org.chromium.components.autofill.FormFieldData)
   */
  public static final native Object MPHorj3A(long nativeFormDataAndroid, Object caller);
}
