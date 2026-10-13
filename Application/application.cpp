#include "application.h"

Application::Application() {
    uie->init0();
}

void Application::update() {
    uie->update();
}

void Application::draw() {
    uie->draw();
}
