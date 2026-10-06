#include "controller.h"
#include "raylib.h"

Controller::Controller() = default;
Controller::~Controller() = default;

void Controller::initKeyBindings(const int k, std::function<void()> f) {
    keyBindings[k] = std::move(f);
}

void Controller::scanKeyBindings() {
    for (auto& [key, func] : keyBindings) {
        if (IsKeyDown(key)) { func(); }
    }
}

Vector2 Controller::getMouse() { return GetMousePosition(); }
