#include "application.h"

Application::Application() {
    uie->init0();
    //uie->init0("../toolkit.hwd");
    /*todo:
     * 1. make menus of certain size and position that are available at startup, not just default.
     * 2.
     *
     */
}

void Application::update() {
    uie->update();
}

void Application::draw() {
    uie->draw();
}
