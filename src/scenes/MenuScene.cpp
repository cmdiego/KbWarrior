#include "scenes/MenuScene.hpp"

void MenuScene::onEnter() {
  // load assets, init UI
  bgTexture_ = TextureRAII("assets/textures/kbwarrior_background.png");
  // fontTexture_ = FontTextureRAII("assets/fonts/kbwarrior_title.png")
}

void MenuScene::onExit() {}

void MenuScene::handleInput() {
  if (IsKeyPressed(KEY_ENTER)) {
    TraceLog(LOG_INFO, "Enter pressed: transition to GameplayScene");
  }
  if (IsKeyPressed(KEY_ESCAPE)) {
    CloseWindow();
  }
}

void MenuScene::update(float dt) {}

void MenuScene::render() {
  // draw current frame
  BeginDrawing();
  ClearBackground(BLACK);

  if (bgTexture_.valid()) {
    DrawTexture(bgTexture_.get(), 0, 0, WHITE);
  }

  if (titleFont_.valid()) {
    DrawTextEx(titleFont_.get(), "Press ENTER to Start", {80, 400}, 32, 2,
               WHITE);
  }

  EndDrawing();
}
