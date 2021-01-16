// This is generated file. Do not modify directly.

#ifndef MEDIA_AUDIO_ANDROID_
#define MEDIA_AUDIO_ANDROID_

#include <stdarg.h>
#include <map>
#include <string>
#include <vector>

#include "base/logging.h"

namespace media_audio_android {
// Individual module initializer functions.
bool IsAaudioInitialized();
void InitializeAaudio(void* module);
void UninitializeAaudio();

// Enum and typedef for umbrella initializer.
enum StubModules {
  kModuleAaudio = 0,
  kNumStubModules
};

typedef std::map<StubModules, std::vector<std::string> > StubPathMap;

// Umbrella initializer for all the modules in this stub file.
bool InitializeStubs(const StubPathMap& path_map);
}  // namespace media_audio_android

#endif  // MEDIA_AUDIO_ANDROID_
