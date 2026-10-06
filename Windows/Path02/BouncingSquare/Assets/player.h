#ifndef H03_01_PLAYER_H
#define H03_01_PLAYER_H
#include <string>

#include "raylib.h"

class PlayerPath02 {

public:
    Rectangle body{};
    PlayerPath02();
    ~PlayerPath02();

    void drawPlayer();

    void jump();
};

#endif //H03_01_PLAYER_H
