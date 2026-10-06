#ifndef H03_01_PLACER_H
#define H03_01_PLACER_H
#include "raylib.h"
#include <vector>

class Placer {
public:
    static std::vector<Rectangle> placeElements(Rectangle container, float spacing, int numElements); //assumes vertical positioning
};

#endif //H03_01_PLACER_H