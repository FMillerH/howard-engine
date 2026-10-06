#include "centerScene.h"

#include <iostream>

#include "../../../Example/player.h"

CenterScene::CenterScene() : //we need a lightweight event system we can pass to any active scene
Scene("CENTER"),
rec(new Rectangle(-1000, -100, 800, 800)),
smallRec(new Rectangle(rec->x + 500, rec->y + 300, 100, 100))
{
}

void CenterScene::runScene() { //todo: build a controller class to avoid recursive boolean checks
    if (IsKeyDown(KEY_LEFT)) {
        c.x -= 250.0f * GetFrameTime();
    }
}

void CenterScene::drawScene() {
    for (const Rectangle* rect : ents) {
        DrawRectanglePro({rect->x + std::abs(c.x), rect->y, rect->width, rect->height},{},0 , GRAY);
    }
    // player->drawPlayer();
}

void CenterScene::endScene() {
    std::cout << "CENTER SCENE ENDED" << std::endl;
}

CenterScene::~CenterScene() = default;
