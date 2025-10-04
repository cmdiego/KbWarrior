#pragma once
#include "raylib.h"
#include <string>

class TextureRAII {
public:
  TextureRAII() = default;
  explicit TextureRAII(const std::string &path); // LoadTexture(path)
  ~TextureRAII();                                // UnloadTexture if valid

  TextureRAII(const TextureRAII &) = delete;
  TextureRAII &operator=(const TextureRAII &) = delete;

  TextureRAII(TextureRAII &&other) noexcept;
  TextureRAII &operator=(TextureRAII &&other) noexcept;

  bool valid() const;
  const Texture2D &get() const;

private:
  Texture2D tex_{};
};
