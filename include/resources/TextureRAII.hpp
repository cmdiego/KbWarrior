#pragma once
#include "raylib.h"
#include <string>

class TextureRAII {
public:
  TextureRAII() = default;
  explicit TextureRAII(const std::string &path); // LoadTexture(path)
  ~TextureRAII();                                // UnloadTexture if valid

  // Disable copy `ctor` and `=` operators
  // We don't want two wrappers pointing to the same GPU texture
  TextureRAII(const TextureRAII &) = delete;            // copy ctor
  TextureRAII &operator=(const TextureRAII &) = delete; // copy assignment

  // Allow move operators
  // TextureRAII texA("menu.png");
  // TextureRAII texB = std::move(texA); // OK. TexA becomes empty, TexB owns
  // texture
  TextureRAII(TextureRAII &&other) noexcept;            // move ctor
  TextureRAII &operator=(TextureRAII &&other) noexcept; // move assignment

  bool valid() const;
  const Texture2D &get() const;

private:
  // Actual Raylib texture handle, stored by value
  Texture2D tex_{};
};
