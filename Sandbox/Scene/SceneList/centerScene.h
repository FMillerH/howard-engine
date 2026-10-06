#ifndef H03_01_CENTERSCENE_H
#define H03_01_CENTERSCENE_H
#include "raylib.h"
#include "../scene.h"

class CenterScene : public Scene {
private:
    std::vector<std::string> directions = {"LEFT", "TOP", "RIGHT"};
    Rectangle* rec;
    Rectangle* smallRec;
    Vector2 c = {0,0};

    std::vector<Rectangle*> ents = { rec, smallRec };

public:

    CenterScene();
    ~CenterScene() override;

    void runScene() override;
    void drawScene() override;
    void endScene() override;
};

#endif //H03_01_CENTERSCENE_H
