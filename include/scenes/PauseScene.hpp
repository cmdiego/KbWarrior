#pragma once
#include "core/Scene.hpp"

class PauseScene : public Scene {
public:
  void onEnter() override; // Intercept input
  void onExit() override;  // Resume gameplay scene
  void handleInput() override;
  void update(float dt) override;
  void render() override;

private:
}
