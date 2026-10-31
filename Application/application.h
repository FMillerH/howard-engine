#ifndef H03_01_APPLICATION_H
#define H03_01_APPLICATION_H
#include <memory>

#include "../ImportedUI/UIenv/uie.h"

class Application {
private:
    std::vector<int> fakeButtons = {1, 2, 3, 4, 5, 6};
    int currentFakeButton = -1;
    Rectangle border;
    Controller controller;
    bool getWindowDelta();


public:
    Application(float windowWidth, float windowHeight);
    void update(int w, int h);
    void draw();
    void initDevController();
    void setPreSelectedButton(int i);
};


#endif //H03_01_APPLICATION_H
