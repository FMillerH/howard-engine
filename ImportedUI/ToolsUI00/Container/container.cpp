#include "container.h"

Container::Container() :
body({0,0,0,0}),
color(RED),
isVisible(false)
{
}

Container::Container(float x, float y, float width, float height, Color color) :
body({x, y, width, height}),
color(color),
isVisible(false)
{
}


void Container::drawContainer() const {
    if (isVisible) {
        DrawRectangleLinesEx(body, 1.0f, color);
    }
}

void Container::setVisible() { //implement checks to avoid unnecessary calls
    isVisible = true;
}

void Container::setInvisible() {
    isVisible = false;
}

Container::~Container() = default;
