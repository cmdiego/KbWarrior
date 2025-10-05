#include "resources/MusicRAII.hpp"
#include "raylib.h"
#include <utility>

/* Dev Notes:
 * The RAII class doesn't call Play/StopSound--that's up to the scene/game
 * logic. Ensure InitAudioDevice() is called once before using sounds/music, and
 * CloseAudioDevice() on shutdown
 */

// load-from-path ctor
MusicRAII::MusicRAII(const std::string &path) {
  music_ = LoadMusicStream(path.c_str());
  // Raylib does expose an "is valid" func for Music;
  // These fields are non-null when a stream is actually loaded
  if (!valid()) {
    TraceLog(LOG_WARNING, "MusicRAII: failed to load music: %s", path.c_str());
  }
}

// Dtor
MusicRAII::~MusicRAII() {
  if (valid()) {
    // if it's playing, stop it before unloading
    StopMusicStream(music_);
    UnloadMusicStream(music_);
    music_ = {}; // leave in a known-empty state
  }
}

// Move ctor: steal the handle and null out the src
MusicRAII::MusicRAII(MusicRAII &&other) noexcept
    : music_{std::exchange(other.music_, {})} {}

// Move ctor: release the current, then steal from src
MusicRAII &MusicRAII::operator=(MusicRAII &&other) noexcept {
  if (this != &other) {
    if (valid()) {
      StopMusicStream(music_);
      UnloadMusicStream(music_);
    }
    music_ = std::exchange(other.music_, {});
  }
  return *this;
}

void MusicRAII::update() {
  if (valid()) {
    UpdateMusicStream(music_);
  }
}

bool MusicRAII::valid() const {
  // Loaded music usually has a non-null stream buffer and/or ctxData
  return (music_.stream.buffer != nullptr) || (music_.ctxData != nullptr);
}

const Music &MusicRAII::get() const { return music_; }
