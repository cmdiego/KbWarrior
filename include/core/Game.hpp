#pragma once
#include "SceneManager.hpp"

class Game {
public:
  Game(int w, int h, const char *title);
  ~Game();

  void run();

  SceneManager &scenes() noexcept { return sceneManager_; }
  const SceneManager &scenes() const noexcept { return sceneManager_; }

private:
  int width_{};
  int height_{};
  bool running{true};
  SceneManager sceneManager_;
};
