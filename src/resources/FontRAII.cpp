#pragma once
#include "resources/FontRAII.hpp"
#include "raylib.h"
#include <utility>

/* Dev Notes:
 * - For TTF smoothing, you can optionally call SetTExtureFilter(font_.texture,
 * TEXTURE_FILTER_BILINEAR) after loading
 * - Use with DrawTextEx(fontRAII.get(), "Hello", {x, y}, fontSize, spacing,
 * color);
 * - If later want size-selectable fonts, add an overload taking size & glyph
 * ranges and use LoadFontEx
 */

FontRAII::FontRAII(const std::string &path) {
  font_ = LoadFont(path.c_str());
  if (!valid()) {
    TraceLog(LOG_WARNING, "FontRAII: failed to load font %s", path.c_str());
  }
}

FontRAII::~FontRAII() {
  if (valid()) {
    UnloadFont(font_);
    font_ = {};
  }
}

FontRAII::FontRAII(FontRAII &&other) noexcept
    // set font_ to what other.font_ was, set other to {}
    : font_{std::exchange(other.font_, {})} {}

FontRAII &FontRAII::operator=(const FontRAII &&other) noexcept {
  if (this != &other) {
    if (valid()) {
      UnloadFont(font_);
    }
    font_ = std::exchange(other.font_, {});
  }
  return *this;
}

bool FontRAII::valid() const {
  // A loaded Font typically has a valid texture and/or glyphs
  return font_.texture.id != 0 || font_.glyphCount > 0;
}

const Font &FontRAII::get() const { return font_; }
