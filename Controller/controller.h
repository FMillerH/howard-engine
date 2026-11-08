#ifndef H03_01_CONTROLLER_H
#define H03_01_CONTROLLER_H
#include <array>
#include <functional>
#include <unordered_map>

#include "raylib.h"

class Controller {
private:

    std::unordered_map<int, std::function<void()>> keyBindings;
    Vector2 mouse = {};

    int makeCombo(int key, int mods) { return key | (mods << 16); }
    int currentMods();

public:
    enum Modifier : int {
        ModNone     = 0,
        ModShift    = 1 << 0,
        ModCtrl     = 1 << 1,
        ModAlt      = 1 << 2,
        ModSuper    = 1 << 3
    };

    Controller();
    ~Controller();

    void initKeyBindings(int k, std::function<void()> f);
    void initKeyBindings(int k, std::function<void()> f, int mods = ModNone);
    void scanKeyBindings();

    Vector2 getMouse();
};

#endif //H03_01_CONTROLLER_H
