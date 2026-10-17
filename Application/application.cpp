#include "application.h"

Application::Application() {
    uie->init0();
}

void Application::update() {
    uie->update();



    /*PLZFIX: Click path: NEW GAME -> OPTIONS -> BACK crashes the program,
     * so there's probably some issue with the menu stack in the UIE. */
}

void Application::draw() {
    uie->draw();
}
