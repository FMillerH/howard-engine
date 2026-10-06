#include "placer.h"

#include <cstdio>

std::vector<Rectangle> Placer::placeElements(Rectangle container, float spacing, int numElements) {
    //assumes vertical positioning
    //TODO: simplify method. All variables are correct and necessary, but do not need to be explicitly restated here.

    std::vector<Rectangle> tempRecs;

    float x = container.x;
    float y = container.y;
    float h = container.height;
    float w = container.width;
    float freeSpace = spacing * static_cast<float>(numElements + 1);

    float xE = x + spacing;
    float hE = (h - freeSpace) / static_cast<float>(numElements);
    float wE = w - (2*spacing);

    for (int i = 0; i < numElements; i++) {
        Rectangle tempRec;
        float yE = y + (static_cast<float>(i + 1) * spacing) + (static_cast<float>(i) * hE);

        tempRec.x = xE;
        tempRec.y = yE;
        tempRec.width = wE;
        tempRec.height = hE;

        tempRecs.push_back(tempRec);

        // printf("y: %f\n", yE);
        // printf("width: %f\n", wE);
    }

    // for (int i = 0; i < numElements; i++)
    // {
    //     printf("<x: %f, y: %f, w: %f, h: %f>\n", tempRecs[i].x, tempRecs[i].y,tempRecs[i].width, tempRecs[i].height);
    // }

    return tempRecs;
}
