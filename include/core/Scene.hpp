#pragma once
class Scene {
public:
  virtual ~Scene() = default;
  virtual void onEnter() {}        // load assets, init UI
  virtual void onExit() {}         // release assets
  virtual void handleInput() {}    // poll keys, map to actions
  virtual void update(float dt) {} // game logic
  virtual void render() {}         // draw current frame
};
