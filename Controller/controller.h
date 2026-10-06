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

public:


    Controller();
    ~Controller();

    void initKeyBindings(int k, std::function<void()> f);
    void scanKeyBindings();

    Vector2 getMouse();
};

#endif //H03_01_CONTROLLER_H
