#include "map.h"

#include "raylib.h"

Map::Map(float x, float y) :
hasPhysics(true),
xBound(x),
yBound(y)
{
}

void Map::drawMap() {
    DrawRectangleLines(10, 10, 500, 500, RED);
}

void Map::pull(PlayerPath02* p) {
    if (hasPhysics && p->body.y >= 500) {
        p->body.y -= 1;
    }
}

Map::~Map() = default;
