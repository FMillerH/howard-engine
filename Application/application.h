#ifndef H03_01_APPLICATION_H
#define H03_01_APPLICATION_H
#include <memory>

#include "../ImportedUI/UIenv/uie.h"

class Application {
private:
    std::unique_ptr<UIenv> uie = std::make_unique<UIenv>();

public:
    Application();
    void update();
    void draw();
};


#endif //H03_01_APPLICATION_H
