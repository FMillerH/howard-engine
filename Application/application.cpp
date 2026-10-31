#include "application.h"

#include <iostream>

Application::Application(float windowWidth, float windowHeight) :
border(50, 50, windowWidth - 100, windowHeight - 100)
{
    initDevController();
}

void Application::update(int w, int h) {

    if (getWindowDelta()) {
        border.width = w - 100;
        border.height = h - 100;
    }
    controller.scanKeyBindings();

    //need a series of CUSTOM menus present on screen  at same time to prove navigation
}

void Application::draw() {
    DrawRectangleLinesEx(border, 1.0, RED);
}

void Application::initDevController() {
    controller.initKeyBindings(264,  [this]() {
        std::cout << "down: null instruction" << std::endl;
        setPreSelectedButton(1);
        std::cout << currentFakeButton << std::endl;
    });

    controller.initKeyBindings(265,  [this]() {
        std::cout << "up: null instruction" << std::endl;
        setPreSelectedButton(-1);
        std::cout << currentFakeButton << std::endl;
    });

}

void Application::setPreSelectedButton(const int i) {
    currentFakeButton += i;

    if (currentFakeButton <= 0) {
        currentFakeButton = fakeButtons.back();
    }

    if (currentFakeButton > fakeButtons.size()) {
        currentFakeButton = 1;
    }
}

bool Application::getWindowDelta() {
    if (GetScreenHeight() - border.width !=0 || GetScreenWidth() - border.height != 0) {
        return true;
    }
    return false;
}
