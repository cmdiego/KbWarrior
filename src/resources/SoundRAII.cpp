#include "resources/SoundRAII.hpp"
#include "raylib.h"
#include <utility>

/* Dev Notes:
 * The RAII class doesn't call Play/StopSound--that's up to the scene/game
 * logic. Ensure InitAudioDevice() is called once before using sounds/music, and
 * CloseAudioDevice() on shutdown
 */

SoundRAII::SoundRAII(const std::string &path) {
  sound_ = LoadSound(path.c_str());
  if (!valid()) {
    TraceLog(LOG_WARNING, "SoundRAII: failed to load sound: %s", path.c_str());
  }
}

SoundRAII::~SoundRAII() {
  if (valid()) {
    UnloadSound(sound_);
    sound_ = {};
  }
}

SoundRAII::SoundRAII(SoundRAII &&other) noexcept
    : sound_{std::exchange(other.sound_, {})} {}

SoundRAII &SoundRAII::operator=(SoundRAII &&other) noexcept {
  // if the other is not the same
  if (this != &other) {
    // and the current is not null
    if (valid()) {
      UnloadSound(sound_);
    }
    // make the current equal to the other, and set the other to empty
    sound_ = std::exchange(other.sound_, {});
  }
  return *this;
}

bool SoundRAII::valid() const {
  // Sound embeds an AudioStream; when loaded its internal buffer -> non-null
  return sound_.stream.buffer != nullptr;
}

const Sound &SoundRAII::get() const { return sound_; }
