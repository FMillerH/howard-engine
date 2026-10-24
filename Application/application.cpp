#include "application.h"

Application::Application() {
    // uie->init0();
    uie->init0("../toolkit.hwd");
}

void Application::update() {
    uie->update();
}

void Application::draw() {
    uie->draw();
}
