#pragma once
#include "core/Scene.hpp"
#include "resources/FontRAII.hpp"
#include "resources/MusicRAII.hpp"
#include "resources/TextureRAII.hpp"

class MenuScene : public Scene {
public:
  void onEnter() override;     // load bg texture, fonts
  void onExit() override;      // unload
  void handleInput() override; // ENTER -> replace with Gameplay
  void update(float dt) override;
  void render() override;

private:
  TextureRAII bgTexture_;
  MusicRAII bgMusic_;
  FontRAII titleFont_;
};
