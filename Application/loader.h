#ifndef H03_01_LOADER_H
#define H03_01_LOADER_H
#include "../Controller/controller.h"

class Loader {
private:
    std::unique_ptr<Controller> controller = std::make_unique<Controller>();




public:
    static std::unique_ptr<Controller> loadController() {

    }
};

#endif //H03_01_LOADER_H
