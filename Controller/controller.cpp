#include "controller.h"

#include <iostream>

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

        else { std::cout << "invalid input: " << makeCombo(key, currentMods()) << std::endl; }

        key = GetKeyPressed();
    }
}

/* scanKeyBindings() enters a while loop for any key that is pressed.
 * makeCombo(key, currentMods()) takes the integer value of the key that was pressed
 *  and calls currentMods(), which performs a bitwise operation depending on whether
 *  a SHIFT key was being held down at the time.
 * In short, a big number is generated each time a key or combination of keys is pressed.
 * This "number" should match the ID of a hardcoded key binding declared elsewhere,
 *  triggering the shortcut.
 */

int Controller::currentMods() {
    int mods = ModNone;
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) mods |= ModShift;
    return mods;
}

Vector2 Controller::getMouse() { return GetMousePosition(); }
