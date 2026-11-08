#include "controller.h"
#include "raylib.h"

Controller::Controller() = default;
Controller::~Controller() = default;

void Controller::initKeyBindings(const int k, std::function<void()> f) {
    keyBindings[k] = std::move(f);
}

void Controller::initKeyBindings(const int k, std::function<void()> f, int mods) {
    keyBindings[makeCombo(k, mods)] = std::move(f);
}

void Controller::scanKeyBindings() {
    int key = GetKeyPressed();

    while (key != 0) {
        auto it = keyBindings.find(makeCombo(key, currentMods()));
        if (it != keyBindings.end()) {
            it->second();
        }

        key = GetKeyPressed();
    }
}

int Controller::currentMods() {
    int mods = ModNone;
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) mods |= ModShift;
    return mods;
}

Vector2 Controller::getMouse() { return GetMousePosition(); }
