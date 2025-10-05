#pragma once
#include "raylib.h"
#include <string>

class SoundRAII {
public:
  SoundRAII() = default;
  explicit SoundRAII(const std::string &path); // LoadSound(Path)
  ~SoundRAII();                                // UnloadSound

  // Disable copy `ctor` and `=` operators
  SoundRAII(const SoundRAII &) = delete;            // copy ctor
  SoundRAII &operator=(const SoundRAII &) = delete; // copy assignment

  // Allow move operators
  SoundRAII(SoundRAII &&other) noexcept;       // move ctor
  SoundRAII &operator=(SoundRAII &&) noexcept; // move assignment

  bool valid() const;
  const Sound &get() const;

private:
  Sound sound_{};
};
