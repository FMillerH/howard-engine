#include "player.h"

Player::Player() :
body(500.0f, 20.0f, 20.0f, 20.0f),
color(RED),
speed(250.0f),
isMoving(false)
{
}

void Player::movePlayer() { //this will need to be simplified later in controller class when built
    if (IsKeyDown(KEY_DOWN)) {
        body.y += GetFrameTime() * speed;
    }

    if (IsKeyDown(KEY_UP)) {
        body.y -= GetFrameTime() * speed;
    }

    if (IsKeyDown(KEY_LEFT)) {
        body.x -= GetFrameTime() * speed;
    }

    if (IsKeyDown(KEY_RIGHT)) {
        body.x += GetFrameTime() * speed;
    }
}

void Player::drawPlayer() {
    DrawRectangleRec(body, color);
}

Vector2 Player::getPlayerPosition2D() {
    return { body.x, body.y };
}

Player::~Player() = default;
