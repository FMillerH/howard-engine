//
// Created by <user> on <date>.
//

#ifndef H03_01_PLAYER_H
#define H03_01_PLAYER_H
#include "raylib.h"

class Player {
private:
    Rectangle body;
    Color color;
    float speed;
    bool isMoving;


public:
    Player();
    ~Player();

    void movePlayer();
    void drawPlayer();
    bool playerIsMoving();

    Vector2 getPlayerPosition2D();
};

#endif //H03_01_PLAYER_H
