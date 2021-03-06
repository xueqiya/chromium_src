// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/browser/MediaSessionImpl

#ifndef org_chromium_content_browser_MediaSessionImpl_JNI
#define org_chromium_content_browser_MediaSessionImpl_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_chromium_content_browser_MediaSessionImpl[];
const char kClassPath_org_chromium_content_browser_MediaSessionImpl[] =
    "org/chromium/content/browser/MediaSessionImpl";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT std::atomic<jclass>
    g_org_chromium_content_browser_MediaSessionImpl_clazz(nullptr);
#ifndef org_chromium_content_browser_MediaSessionImpl_clazz_defined
#define org_chromium_content_browser_MediaSessionImpl_clazz_defined
inline jclass org_chromium_content_browser_MediaSessionImpl_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_chromium_content_browser_MediaSessionImpl,
      &g_org_chromium_content_browser_MediaSessionImpl_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace content {

JNI_GENERATOR_EXPORT void Java_J_N_MlezJYnz(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "Resume");
  return native->Resume(env, base::android::JavaParamRef<jobject>(env, caller));
}

JNI_GENERATOR_EXPORT void Java_J_N_M5LC9gX_00024(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "Suspend");
  return native->Suspend(env, base::android::JavaParamRef<jobject>(env, caller));
}

JNI_GENERATOR_EXPORT void Java_J_N_MW5s36cs(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "Stop");
  return native->Stop(env, base::android::JavaParamRef<jobject>(env, caller));
}

JNI_GENERATOR_EXPORT void Java_J_N_My_1T5ZML(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller,
    jlong millis) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "Seek");
  return native->Seek(env, base::android::JavaParamRef<jobject>(env, caller), millis);
}

JNI_GENERATOR_EXPORT void Java_J_N_MK7btVfc(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller,
    jlong millis) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "SeekTo");
  return native->SeekTo(env, base::android::JavaParamRef<jobject>(env, caller), millis);
}

JNI_GENERATOR_EXPORT void Java_J_N_MAqRqyJa(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller,
    jint action) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "DidReceiveAction");
  return native->DidReceiveAction(env, base::android::JavaParamRef<jobject>(env, caller), action);
}

JNI_GENERATOR_EXPORT void Java_J_N_MdnoDrDw(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeMediaSessionAndroid,
    jobject caller) {
  MediaSessionAndroid* native = reinterpret_cast<MediaSessionAndroid*>(nativeMediaSessionAndroid);
  CHECK_NATIVE_PTR(env, jcaller, native, "RequestSystemAudioFocus");
  return native->RequestSystemAudioFocus(env, base::android::JavaParamRef<jobject>(env, caller));
}

static base::android::ScopedJavaLocalRef<jobject>
    JNI_MediaSessionImpl_GetMediaSessionFromWebContents(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& contents);

JNI_GENERATOR_EXPORT jobject Java_J_N_Mtun_00024qW8(
    JNIEnv* env,
    jclass jcaller,
    jobject contents) {
  return JNI_MediaSessionImpl_GetMediaSessionFromWebContents(env,
      base::android::JavaParamRef<jobject>(env, contents)).Release();
}


static std::atomic<jmethodID> g_org_chromium_content_browser_MediaSessionImpl_hasObservers(nullptr);
static jboolean Java_MediaSessionImpl_hasObservers(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env), false);

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "hasObservers",
          "()Z",
          &g_org_chromium_content_browser_MediaSessionImpl_hasObservers);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID>
    g_org_chromium_content_browser_MediaSessionImpl_mediaSessionDestroyed(nullptr);
static void Java_MediaSessionImpl_mediaSessionDestroyed(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env));

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "mediaSessionDestroyed",
          "()V",
          &g_org_chromium_content_browser_MediaSessionImpl_mediaSessionDestroyed);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id);
}

static std::atomic<jmethodID>
    g_org_chromium_content_browser_MediaSessionImpl_mediaSessionStateChanged(nullptr);
static void Java_MediaSessionImpl_mediaSessionStateChanged(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jboolean isControllable,
    jboolean isSuspended) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env));

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "mediaSessionStateChanged",
          "(ZZ)V",
          &g_org_chromium_content_browser_MediaSessionImpl_mediaSessionStateChanged);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, isControllable, isSuspended);
}

static std::atomic<jmethodID>
    g_org_chromium_content_browser_MediaSessionImpl_mediaSessionMetadataChanged(nullptr);
static void Java_MediaSessionImpl_mediaSessionMetadataChanged(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>& metadata) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env));

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "mediaSessionMetadataChanged",
          "(Lorg/chromium/services/media_session/MediaMetadata;)V",
          &g_org_chromium_content_browser_MediaSessionImpl_mediaSessionMetadataChanged);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, metadata.obj());
}

static std::atomic<jmethodID>
    g_org_chromium_content_browser_MediaSessionImpl_mediaSessionActionsChanged(nullptr);
static void Java_MediaSessionImpl_mediaSessionActionsChanged(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jintArray>& actions) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env));

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "mediaSessionActionsChanged",
          "([I)V",
          &g_org_chromium_content_browser_MediaSessionImpl_mediaSessionActionsChanged);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, actions.obj());
}

static std::atomic<jmethodID>
    g_org_chromium_content_browser_MediaSessionImpl_mediaSessionArtworkChanged(nullptr);
static void Java_MediaSessionImpl_mediaSessionArtworkChanged(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobjectArray>& images) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env));

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "mediaSessionArtworkChanged",
          "([Lorg/chromium/services/media_session/MediaImage;)V",
          &g_org_chromium_content_browser_MediaSessionImpl_mediaSessionArtworkChanged);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, images.obj());
}

static std::atomic<jmethodID>
    g_org_chromium_content_browser_MediaSessionImpl_mediaSessionPositionChanged(nullptr);
static void Java_MediaSessionImpl_mediaSessionPositionChanged(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>& position) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_chromium_content_browser_MediaSessionImpl_clazz(env));

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "mediaSessionPositionChanged",
          "(Lorg/chromium/services/media_session/MediaPosition;)V",
          &g_org_chromium_content_browser_MediaSessionImpl_mediaSessionPositionChanged);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, position.obj());
}

static std::atomic<jmethodID> g_org_chromium_content_browser_MediaSessionImpl_create(nullptr);
static base::android::ScopedJavaLocalRef<jobject> Java_MediaSessionImpl_create(JNIEnv* env, jlong
    nativeMediaSession) {
  jclass clazz = org_chromium_content_browser_MediaSessionImpl_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_chromium_content_browser_MediaSessionImpl_clazz(env), NULL);

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "create",
          "(J)Lorg/chromium/content/browser/MediaSessionImpl;",
          &g_org_chromium_content_browser_MediaSessionImpl_create);

  jobject ret =
      env->CallStaticObjectMethod(clazz,
          call_context.base.method_id, nativeMediaSession);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace content

// Step 4: Generated test functions (optional).


#endif  // org_chromium_content_browser_MediaSessionImpl_JNI
