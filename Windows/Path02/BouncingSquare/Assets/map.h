#ifndef H03_01_MAP_H
#define H03_01_MAP_H
#include <vector>

#include "player.h"

class Map {
public:
    bool hasPhysics;
    float xBound;
    float yBound;
    std::vector<PlayerPath02*> players;

    Map(float x, float y);
    void drawMap();
    void pull(PlayerPath02* p);
    ~Map();
};

#endif //H03_01_MAP_H
