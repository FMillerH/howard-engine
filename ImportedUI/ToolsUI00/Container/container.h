#ifndef H03_01_CONTAINER_H
#define H03_01_CONTAINER_H
#include "raylib.h"

class Container {
public:
    Rectangle body;
    Color color;
    bool isVisible;


    Container();
    Container(float x, float y, float width, float height, Color color);
    virtual ~Container();

    virtual void drawContainer() const;
    virtual void setVisible();
    virtual void setInvisible();
};

#endif //H03_01_CONTAINER_H