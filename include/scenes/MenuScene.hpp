#pragma once
#include "core/Scene.hpp"

class MenuScene : public Scene {
public:
  void onEnter() override;     // load bg texture, fonts
  void onExit() override;      // unload
  void handleInput() override; // ENTER -> replace with Gameplay
  void update(float dt) override;
  void render() override;

private:
  // Insert resource wrappers here (RAII)
};
