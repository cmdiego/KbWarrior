#pragma once
#include "core/Scene.hpp"

class GameplayScene : public Scene {
public:
  void onEnter() override;     // load level data
  void onExit() override;      // release level
  void handleInput() override; // ESC -> push PauseScene
  void update(float dt) override;
  void render() override;

private:
}
