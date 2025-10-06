#pragma once
#include "raylib.h"
#include <string>

class MusicRAII {
public:
  MusicRAII() = default;
  explicit MusicRAII(const std::string &path); // LoadMusicStream
  ~MusicRAII();                                // UnloadMusicStream

  // Disable copy `ctor` and `=` operators
  MusicRAII(const MusicRAII &) = delete;            // copy ctor
  MusicRAII &operator=(const MusicRAII &) = delete; // copy assignment

  // Allow move operators
  MusicRAII(MusicRAII &&other) noexcept;       // move ctor
  MusicRAII &operator=(MusicRAII &&) noexcept; // move assignment

  void update(); // UpdateMusicStream per frame
  bool valid() const;
  const Music &get() const;

private:
  Music music_{};
};
