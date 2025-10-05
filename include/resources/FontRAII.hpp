#pragma once
#include "raylib.h"
#include <string>

class FontRAII {
public:
  FontRAII() = default;
  explicit FontRAII(const std::string &path); // LoadFont(Path)
  ~FontRAII();                                // UnloadFont

  // Disable copy `ctor` and `=` operators
  FontRAII(const FontRAII &) = delete;            // copy ctor
  FontRAII &operator=(const FontRAII &) = delete; // copy assignment

  // Allow move operators
  FontRAII(FontRAII &&other) noexcept;       // move ctor
  FontRAII &operator=(FontRAII &&) noexcept; // move assignment

  bool valid() const;
  const Font &get() const;

private:
  Font font_{};
};
