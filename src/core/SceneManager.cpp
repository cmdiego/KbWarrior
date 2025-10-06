#include "core/SceneManager.hpp"
#include <cassert>
#include <utility>

void SceneManager::push(ScenePtr s) {
  assert(s && "SceneManager::push received null scene");
  // Use move since ScenePtr == unique_ptr
  stack_.push_back(std::move(s));
  stack_.back()->onEnter();
}

void SceneManager::pop() {
  assert(!stack_.empty() && "SceneManager::pop called on empty stack");
  stack_.back()->onExit();
  stack_.pop_back();
}

void SceneManager::replace(ScenePtr s) {
  assert(s && "SceneManager::replace received null scene");
  if (!stack_.empty()) {
    pop();
  }
  push(std::move(s));
}

Scene &SceneManager::top() {
  assert(!stack_.empty() && "SceneManager::top called on empty stack");
  return *stack_.back();
}

// Read-only overload
const Scene &SceneManager::top() const {
  assert(!stack_.empty() && "SceneManager::top called on empty stack");
  return *stack_.back();
}

/* Helpers */
void SceneManager::clear() {
  while (!stack_.empty())
    pop();
}
