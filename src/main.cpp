#include "core/Game.hpp"
#include "raylib.h"
#include "scenes/MenuScene.hpp"
#include <iostream>

using namespace std;

const struct {
  int width = 800;
  int height = 700;
} windowScreen;

int main() {
  InitWindow(windowScreen.width, windowScreen.height, "Hello, warrior!");
  SetTargetFPS(60);
  Texture2D background = LoadTexture("assets/background.png");
  // Game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(background, 0, 0, WHITE);
    UnloadTexture(background);
    EndDrawing();
  }

  CloseWindow();
}
