#include "player.h"

PlayerPath02::PlayerPath02() {
    body.x = 50.0f;
    body.y = 50.0f;
    body.width = 50.0f;
    body.height = 50.0f;
}

PlayerPath02::~PlayerPath02() = default;

void PlayerPath02::drawPlayer() {
    DrawRectangleRec(body, WHITE);
}

void PlayerPath02::jump() {

}
