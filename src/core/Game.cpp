#include "core/Game.hpp"
#include "raylib.h"

// Constructor: initialize window + timing
Game::Game(int w, int h, const char *title) {
  width_ = w;
  height_ = h;

  // Basic window config (tweak as needed)
  SetConfigFlags(FLAG_VSYNC_HINT); // reduces tearing; optional
  InitWindow(w, h, title);
  SetTargetFPS(60);
}

// Destructor: orderly shutdown
Game::~Game() {
  // Ensure scenes exit in LIFO order; calls onExit() for each
  this->scenes().clear();

  // Close Raylib window/context
  if (IsWindowReady()) {
    CloseWindow();
  }
}

// Main loop
void Game::run() {
  // Exit if nothing to run
  if (this->scenes().empty()) {
    return;
  }

  while (!WindowShouldClose()) {
    // If all scenes were popped, exit the loop
    if (this->scenes().empty())
      break;

    // Active scene
    auto &scene = this->scenes().top();

    // 1) Input
    scene.handleInput();

    // 2) Update (seconds since last frame)
    const float dt = GetFrameTime();
    scene.update(dt);

    // 3) Render
    BeginDrawing();
    ClearBackground(BLACK); // Customize as needed
    scene.render();
    EndDrawing();
  }
}
