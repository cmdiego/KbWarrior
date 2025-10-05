#pragma once
#include "Scene.hpp"
#include <memory>
#include <vector>

class SceneManager {
public:
  using ScenePtr = std::unique_ptr<Scene>;

  void push(ScenePtr s);    // call s->onEnter()
  void pop();               // call top->onExit()
  void replace(ScenePtr s); // pop(); push(new)

  Scene &top();
  const Scene &top() const;

  bool empty() const noexcept { return stack_.empty(); }
  std::size_t size() const noexcept { return stack_.size(); }
  void clear();

private:
  std::vector<ScenePtr> stack_;
};
