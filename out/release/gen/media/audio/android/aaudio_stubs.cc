// This is generated file. Do not modify directly.

#include "media/audio/android/aaudio_stubs.h"

#include <stdlib.h>  // For NULL.
#include <dlfcn.h>   // For dlsym, dlopen.

#include <map>
#include <vector>

// The extra include header needed in the generated stub file for defining
// various AAudio types.

extern "C" {

#include <aaudio/AAudio.h>

}

extern "C" {

// Static pointers that will hold the location of the real function
// implementations after the module has been loaded.
static const char * (*AAudio_convertResultToText_ptr)(aaudio_result_t returnCode) = NULL;
static aaudio_result_t (*AAudio_createStreamBuilder_ptr)(AAudioStreamBuilder** builder) = NULL;
static void (*AAudioStreamBuilder_setDeviceId_ptr)(AAudioStreamBuilder* builder, int32_t deviceId) = NULL;
static void (*AAudioStreamBuilder_setSampleRate_ptr)(AAudioStreamBuilder* builder, int32_t sampleRate) = NULL;
static void (*AAudioStreamBuilder_setChannelCount_ptr)(AAudioStreamBuilder* builder, int32_t channelCount) = NULL;
static void (*AAudioStreamBuilder_setSamplesPerFrame_ptr)(AAudioStreamBuilder* builder, int32_t samplesPerFrame) = NULL;
static void (*AAudioStreamBuilder_setFormat_ptr)(AAudioStreamBuilder* builder, aaudio_format_t format) = NULL;
static void (*AAudioStreamBuilder_setDirection_ptr)(AAudioStreamBuilder* builder, aaudio_direction_t direction) = NULL;
static void (*AAudioStreamBuilder_setBufferCapacityInFrames_ptr)(AAudioStreamBuilder* builder, int32_t numFrames) = NULL;
static void (*AAudioStreamBuilder_setPerformanceMode_ptr)(AAudioStreamBuilder* builder, aaudio_performance_mode_t mode) = NULL;
static void (*AAudioStreamBuilder_setFramesPerDataCallback_ptr)(AAudioStreamBuilder* builder, int32_t numFrames) = NULL;
static void (*AAudioStreamBuilder_setUsage_ptr)(AAudioStreamBuilder* builder, aaudio_usage_t usage) = NULL;
static void (*AAudioStreamBuilder_setDataCallback_ptr)(AAudioStreamBuilder* builder, AAudioStream_dataCallback callback, void *userData) = NULL;
static void (*AAudioStreamBuilder_setErrorCallback_ptr)(AAudioStreamBuilder* builder, AAudioStream_errorCallback callback, void *userData) = NULL;
static aaudio_result_t (*AAudioStreamBuilder_openStream_ptr)(AAudioStreamBuilder* builder, AAudioStream** stream) = NULL;
static aaudio_result_t (*AAudioStreamBuilder_delete_ptr)(AAudioStreamBuilder* builder) = NULL;
static aaudio_result_t (*AAudioStream_close_ptr)(AAudioStream* stream) = NULL;
static aaudio_result_t (*AAudioStream_requestStart_ptr)(AAudioStream* stream) = NULL;
static aaudio_result_t (*AAudioStream_requestStop_ptr)(AAudioStream* stream) = NULL;
static aaudio_result_t (*AAudioStream_getTimestamp_ptr)(AAudioStream* stream, clockid_t clockid, int64_t *framePosition, int64_t *timeNanoseconds) = NULL;
static int64_t (*AAudioStream_getFramesWritten_ptr)(AAudioStream* stream) = NULL;

// Stubs that dispatch to the real implementations.
extern const char * AAudio_convertResultToText(aaudio_result_t returnCode) __attribute__((weak));
const char *  AAudio_convertResultToText(aaudio_result_t returnCode) {
  return AAudio_convertResultToText_ptr(returnCode);
}
extern aaudio_result_t AAudio_createStreamBuilder(AAudioStreamBuilder** builder) __attribute__((weak));
aaudio_result_t  AAudio_createStreamBuilder(AAudioStreamBuilder** builder) {
  return AAudio_createStreamBuilder_ptr(builder);
}
extern void AAudioStreamBuilder_setDeviceId(AAudioStreamBuilder* builder, int32_t deviceId) __attribute__((weak));
void  AAudioStreamBuilder_setDeviceId(AAudioStreamBuilder* builder, int32_t deviceId) {
  AAudioStreamBuilder_setDeviceId_ptr(builder, deviceId);
}
extern void AAudioStreamBuilder_setSampleRate(AAudioStreamBuilder* builder, int32_t sampleRate) __attribute__((weak));
void  AAudioStreamBuilder_setSampleRate(AAudioStreamBuilder* builder, int32_t sampleRate) {
  AAudioStreamBuilder_setSampleRate_ptr(builder, sampleRate);
}
extern void AAudioStreamBuilder_setChannelCount(AAudioStreamBuilder* builder, int32_t channelCount) __attribute__((weak));
void  AAudioStreamBuilder_setChannelCount(AAudioStreamBuilder* builder, int32_t channelCount) {
  AAudioStreamBuilder_setChannelCount_ptr(builder, channelCount);
}
extern void AAudioStreamBuilder_setSamplesPerFrame(AAudioStreamBuilder* builder, int32_t samplesPerFrame) __attribute__((weak));
void  AAudioStreamBuilder_setSamplesPerFrame(AAudioStreamBuilder* builder, int32_t samplesPerFrame) {
  AAudioStreamBuilder_setSamplesPerFrame_ptr(builder, samplesPerFrame);
}
extern void AAudioStreamBuilder_setFormat(AAudioStreamBuilder* builder, aaudio_format_t format) __attribute__((weak));
void  AAudioStreamBuilder_setFormat(AAudioStreamBuilder* builder, aaudio_format_t format) {
  AAudioStreamBuilder_setFormat_ptr(builder, format);
}
extern void AAudioStreamBuilder_setDirection(AAudioStreamBuilder* builder, aaudio_direction_t direction) __attribute__((weak));
void  AAudioStreamBuilder_setDirection(AAudioStreamBuilder* builder, aaudio_direction_t direction) {
  AAudioStreamBuilder_setDirection_ptr(builder, direction);
}
extern void AAudioStreamBuilder_setBufferCapacityInFrames(AAudioStreamBuilder* builder, int32_t numFrames) __attribute__((weak));
void  AAudioStreamBuilder_setBufferCapacityInFrames(AAudioStreamBuilder* builder, int32_t numFrames) {
  AAudioStreamBuilder_setBufferCapacityInFrames_ptr(builder, numFrames);
}
extern void AAudioStreamBuilder_setPerformanceMode(AAudioStreamBuilder* builder, aaudio_performance_mode_t mode) __attribute__((weak));
void  AAudioStreamBuilder_setPerformanceMode(AAudioStreamBuilder* builder, aaudio_performance_mode_t mode) {
  AAudioStreamBuilder_setPerformanceMode_ptr(builder, mode);
}
extern void AAudioStreamBuilder_setFramesPerDataCallback(AAudioStreamBuilder* builder, int32_t numFrames) __attribute__((weak));
void  AAudioStreamBuilder_setFramesPerDataCallback(AAudioStreamBuilder* builder, int32_t numFrames) {
  AAudioStreamBuilder_setFramesPerDataCallback_ptr(builder, numFrames);
}
extern void AAudioStreamBuilder_setUsage(AAudioStreamBuilder* builder, aaudio_usage_t usage) __attribute__((weak));
void  AAudioStreamBuilder_setUsage(AAudioStreamBuilder* builder, aaudio_usage_t usage) {
  AAudioStreamBuilder_setUsage_ptr(builder, usage);
}
extern void AAudioStreamBuilder_setDataCallback(AAudioStreamBuilder* builder, AAudioStream_dataCallback callback, void *userData) __attribute__((weak));
void  AAudioStreamBuilder_setDataCallback(AAudioStreamBuilder* builder, AAudioStream_dataCallback callback, void *userData) {
  AAudioStreamBuilder_setDataCallback_ptr(builder, callback, userData);
}
extern void AAudioStreamBuilder_setErrorCallback(AAudioStreamBuilder* builder, AAudioStream_errorCallback callback, void *userData) __attribute__((weak));
void  AAudioStreamBuilder_setErrorCallback(AAudioStreamBuilder* builder, AAudioStream_errorCallback callback, void *userData) {
  AAudioStreamBuilder_setErrorCallback_ptr(builder, callback, userData);
}
extern aaudio_result_t AAudioStreamBuilder_openStream(AAudioStreamBuilder* builder, AAudioStream** stream) __attribute__((weak));
aaudio_result_t  AAudioStreamBuilder_openStream(AAudioStreamBuilder* builder, AAudioStream** stream) {
  return AAudioStreamBuilder_openStream_ptr(builder, stream);
}
extern aaudio_result_t AAudioStreamBuilder_delete(AAudioStreamBuilder* builder) __attribute__((weak));
aaudio_result_t  AAudioStreamBuilder_delete(AAudioStreamBuilder* builder) {
  return AAudioStreamBuilder_delete_ptr(builder);
}
extern aaudio_result_t AAudioStream_close(AAudioStream* stream) __attribute__((weak));
aaudio_result_t  AAudioStream_close(AAudioStream* stream) {
  return AAudioStream_close_ptr(stream);
}
extern aaudio_result_t AAudioStream_requestStart(AAudioStream* stream) __attribute__((weak));
aaudio_result_t  AAudioStream_requestStart(AAudioStream* stream) {
  return AAudioStream_requestStart_ptr(stream);
}
extern aaudio_result_t AAudioStream_requestStop(AAudioStream* stream) __attribute__((weak));
aaudio_result_t  AAudioStream_requestStop(AAudioStream* stream) {
  return AAudioStream_requestStop_ptr(stream);
}
extern aaudio_result_t AAudioStream_getTimestamp(AAudioStream* stream, clockid_t clockid, int64_t *framePosition, int64_t *timeNanoseconds) __attribute__((weak));
aaudio_result_t  AAudioStream_getTimestamp(AAudioStream* stream, clockid_t clockid, int64_t *framePosition, int64_t *timeNanoseconds) {
  return AAudioStream_getTimestamp_ptr(stream, clockid, framePosition, timeNanoseconds);
}
extern int64_t AAudioStream_getFramesWritten(AAudioStream* stream) __attribute__((weak));
int64_t  AAudioStream_getFramesWritten(AAudioStream* stream) {
  return AAudioStream_getFramesWritten_ptr(stream);
}

}  // extern "C"


namespace media_audio_android {

// Returns true if all stubs have been properly initialized.
bool IsAaudioInitialized() {
  if (AAudio_convertResultToText_ptr &&
      AAudio_createStreamBuilder_ptr &&
      AAudioStreamBuilder_setDeviceId_ptr &&
      AAudioStreamBuilder_setSampleRate_ptr &&
      AAudioStreamBuilder_setChannelCount_ptr &&
      AAudioStreamBuilder_setSamplesPerFrame_ptr &&
      AAudioStreamBuilder_setFormat_ptr &&
      AAudioStreamBuilder_setDirection_ptr &&
      AAudioStreamBuilder_setBufferCapacityInFrames_ptr &&
      AAudioStreamBuilder_setPerformanceMode_ptr &&
      AAudioStreamBuilder_setFramesPerDataCallback_ptr &&
      AAudioStreamBuilder_setUsage_ptr &&
      AAudioStreamBuilder_setDataCallback_ptr &&
      AAudioStreamBuilder_setErrorCallback_ptr &&
      AAudioStreamBuilder_openStream_ptr &&
      AAudioStreamBuilder_delete_ptr &&
      AAudioStream_close_ptr &&
      AAudioStream_requestStart_ptr &&
      AAudioStream_requestStop_ptr &&
      AAudioStream_getTimestamp_ptr &&
      AAudioStream_getFramesWritten_ptr) {
    return true;
  } else {
    return false;
  }
}

// Initializes the module stubs.
void InitializeAaudio(void* module) {
  AAudio_convertResultToText_ptr =
    reinterpret_cast<const char * (*)(aaudio_result_t returnCode)>(
      dlsym(module, "AAudio_convertResultToText"));
  if (!AAudio_convertResultToText_ptr) {
    VLOG(1) << "Couldn't load AAudio_convertResultToText, dlerror() says:\n"
      << dlerror();
  }
  AAudio_createStreamBuilder_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStreamBuilder** builder)>(
      dlsym(module, "AAudio_createStreamBuilder"));
  if (!AAudio_createStreamBuilder_ptr) {
    VLOG(1) << "Couldn't load AAudio_createStreamBuilder, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setDeviceId_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, int32_t deviceId)>(
      dlsym(module, "AAudioStreamBuilder_setDeviceId"));
  if (!AAudioStreamBuilder_setDeviceId_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setDeviceId, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setSampleRate_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, int32_t sampleRate)>(
      dlsym(module, "AAudioStreamBuilder_setSampleRate"));
  if (!AAudioStreamBuilder_setSampleRate_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setSampleRate, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setChannelCount_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, int32_t channelCount)>(
      dlsym(module, "AAudioStreamBuilder_setChannelCount"));
  if (!AAudioStreamBuilder_setChannelCount_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setChannelCount, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setSamplesPerFrame_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, int32_t samplesPerFrame)>(
      dlsym(module, "AAudioStreamBuilder_setSamplesPerFrame"));
  if (!AAudioStreamBuilder_setSamplesPerFrame_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setSamplesPerFrame, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setFormat_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, aaudio_format_t format)>(
      dlsym(module, "AAudioStreamBuilder_setFormat"));
  if (!AAudioStreamBuilder_setFormat_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setFormat, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setDirection_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, aaudio_direction_t direction)>(
      dlsym(module, "AAudioStreamBuilder_setDirection"));
  if (!AAudioStreamBuilder_setDirection_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setDirection, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setBufferCapacityInFrames_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, int32_t numFrames)>(
      dlsym(module, "AAudioStreamBuilder_setBufferCapacityInFrames"));
  if (!AAudioStreamBuilder_setBufferCapacityInFrames_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setBufferCapacityInFrames, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setPerformanceMode_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, aaudio_performance_mode_t mode)>(
      dlsym(module, "AAudioStreamBuilder_setPerformanceMode"));
  if (!AAudioStreamBuilder_setPerformanceMode_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setPerformanceMode, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setFramesPerDataCallback_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, int32_t numFrames)>(
      dlsym(module, "AAudioStreamBuilder_setFramesPerDataCallback"));
  if (!AAudioStreamBuilder_setFramesPerDataCallback_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setFramesPerDataCallback, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setUsage_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, aaudio_usage_t usage)>(
      dlsym(module, "AAudioStreamBuilder_setUsage"));
  if (!AAudioStreamBuilder_setUsage_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setUsage, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setDataCallback_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, AAudioStream_dataCallback callback, void *userData)>(
      dlsym(module, "AAudioStreamBuilder_setDataCallback"));
  if (!AAudioStreamBuilder_setDataCallback_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setDataCallback, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_setErrorCallback_ptr =
    reinterpret_cast<void (*)(AAudioStreamBuilder* builder, AAudioStream_errorCallback callback, void *userData)>(
      dlsym(module, "AAudioStreamBuilder_setErrorCallback"));
  if (!AAudioStreamBuilder_setErrorCallback_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_setErrorCallback, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_openStream_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStreamBuilder* builder, AAudioStream** stream)>(
      dlsym(module, "AAudioStreamBuilder_openStream"));
  if (!AAudioStreamBuilder_openStream_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_openStream, dlerror() says:\n"
      << dlerror();
  }
  AAudioStreamBuilder_delete_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStreamBuilder* builder)>(
      dlsym(module, "AAudioStreamBuilder_delete"));
  if (!AAudioStreamBuilder_delete_ptr) {
    VLOG(1) << "Couldn't load AAudioStreamBuilder_delete, dlerror() says:\n"
      << dlerror();
  }
  AAudioStream_close_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStream* stream)>(
      dlsym(module, "AAudioStream_close"));
  if (!AAudioStream_close_ptr) {
    VLOG(1) << "Couldn't load AAudioStream_close, dlerror() says:\n"
      << dlerror();
  }
  AAudioStream_requestStart_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStream* stream)>(
      dlsym(module, "AAudioStream_requestStart"));
  if (!AAudioStream_requestStart_ptr) {
    VLOG(1) << "Couldn't load AAudioStream_requestStart, dlerror() says:\n"
      << dlerror();
  }
  AAudioStream_requestStop_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStream* stream)>(
      dlsym(module, "AAudioStream_requestStop"));
  if (!AAudioStream_requestStop_ptr) {
    VLOG(1) << "Couldn't load AAudioStream_requestStop, dlerror() says:\n"
      << dlerror();
  }
  AAudioStream_getTimestamp_ptr =
    reinterpret_cast<aaudio_result_t (*)(AAudioStream* stream, clockid_t clockid, int64_t *framePosition, int64_t *timeNanoseconds)>(
      dlsym(module, "AAudioStream_getTimestamp"));
  if (!AAudioStream_getTimestamp_ptr) {
    VLOG(1) << "Couldn't load AAudioStream_getTimestamp, dlerror() says:\n"
      << dlerror();
  }
  AAudioStream_getFramesWritten_ptr =
    reinterpret_cast<int64_t (*)(AAudioStream* stream)>(
      dlsym(module, "AAudioStream_getFramesWritten"));
  if (!AAudioStream_getFramesWritten_ptr) {
    VLOG(1) << "Couldn't load AAudioStream_getFramesWritten, dlerror() says:\n"
      << dlerror();
  }
}

// Uninitialize the module stubs.  Reset pointers to NULL.
void UninitializeAaudio() {
  AAudio_convertResultToText_ptr = NULL;
  AAudio_createStreamBuilder_ptr = NULL;
  AAudioStreamBuilder_setDeviceId_ptr = NULL;
  AAudioStreamBuilder_setSampleRate_ptr = NULL;
  AAudioStreamBuilder_setChannelCount_ptr = NULL;
  AAudioStreamBuilder_setSamplesPerFrame_ptr = NULL;
  AAudioStreamBuilder_setFormat_ptr = NULL;
  AAudioStreamBuilder_setDirection_ptr = NULL;
  AAudioStreamBuilder_setBufferCapacityInFrames_ptr = NULL;
  AAudioStreamBuilder_setPerformanceMode_ptr = NULL;
  AAudioStreamBuilder_setFramesPerDataCallback_ptr = NULL;
  AAudioStreamBuilder_setUsage_ptr = NULL;
  AAudioStreamBuilder_setDataCallback_ptr = NULL;
  AAudioStreamBuilder_setErrorCallback_ptr = NULL;
  AAudioStreamBuilder_openStream_ptr = NULL;
  AAudioStreamBuilder_delete_ptr = NULL;
  AAudioStream_close_ptr = NULL;
  AAudioStream_requestStart_ptr = NULL;
  AAudioStream_requestStop_ptr = NULL;
  AAudioStream_getTimestamp_ptr = NULL;
  AAudioStream_getFramesWritten_ptr = NULL;
}

}  // namespace media_audio_android

namespace media_audio_android {
typedef std::map<StubModules, void*> StubHandleMap;
static void CloseLibraries(StubHandleMap* stub_handles) {
  for (StubHandleMap::const_iterator it = stub_handles->begin();
       it != stub_handles->end();
       ++it) {
    dlclose(it->second);
  }

  stub_handles->clear();
}
bool InitializeStubs(const StubPathMap& path_map) {
  StubHandleMap opened_libraries;
  for (int i = 0; i < kNumStubModules; ++i) {
    StubModules cur_module = static_cast<StubModules>(i);
    // If a module is missing, we fail.
    StubPathMap::const_iterator it = path_map.find(cur_module);
    if (it == path_map.end()) {
      CloseLibraries(&opened_libraries);
      return false;
    }

    // Otherwise, attempt to dlopen the library.
    const std::vector<std::string>& paths = it->second;
    bool module_opened = false;
    for (std::vector<std::string>::const_iterator dso_path = paths.begin();
         !module_opened && dso_path != paths.end();
         ++dso_path) {
      void* handle = dlopen(dso_path->c_str(), RTLD_LAZY);
      if (handle != NULL) {
        module_opened = true;
        opened_libraries[cur_module] = handle;
      } else {
        VLOG(1) << "dlopen(" << dso_path->c_str() << ") failed, "
                << "dlerror() says:\n" << dlerror();
      }
    }

    if (!module_opened) {
      CloseLibraries(&opened_libraries);
      return false;
    }
  }

  // Initialize each module if we have not already failed.
  InitializeAaudio(opened_libraries[kModuleAaudio]);

  // Check that each module is initialized correctly.
  // Close all previously opened libraries on failure.
  if (!IsAaudioInitialized()) {
    UninitializeAaudio();
    CloseLibraries(&opened_libraries);
    return false;
  }

  return true;
}

}  // namespace media_audio_android
