#include "resources/TextureRAII.hpp"
#include "raylib.h"
#include <utility> // std::exchange

// Load-from-path constructor
TextureRAII::TextureRAII(const std::string &path) {
  tex_ = LoadTexture(path.c_str());
  if (!valid()) {
    TraceLog(LOG_WARNING, "TextureRAII: failed to load texture: %s",
             path.c_str());
  }
}

// Dstor releases the GPU handle if it's valid
TextureRAII::~TextureRAII() {
  if (tex_.id != 0) {
    UnloadTexture(tex_);
    tex_ = {}; // leave in known-empty state
  }
}

// Move ctor: Steal the handle and null out the source
TextureRAII &TextureRAII::operator=(TextureRAII &&other) noexcept {
  if (this != &other) {
    if (tex_.id != 0) {
      UnloadTexture(tex_);
    }
    // exchange: Swap value w/ new one, returns old one
    tex_ = std::exchange(other.tex_, {});
  }
  // return reference to the current object
  return *this;
}

// Query if the underlying Raylib texture is valid
bool TextureRAII::valid() const { return tex_.id != 0; }

// Read-only access to the Raylib texture2D
const Texture2D &TextureRAII::get() const { return tex_; }
