#include "application.h"

#include <iostream>

Application::Application(float windowWidth, float windowHeight) :
border(50, 50, windowWidth - 100, windowHeight - 100)
{
    initDevController();
    containerTest();
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

    for (Container* container : fakeMenus) {
        container->drawContainer();
    }
}

void Application::initDevController() {}

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

void Application::containerTest() {
    std::vector<Container*> containers;
    std::vector colors = {PURPLE, YELLOW, GREEN};


    for (int i = 0; i < 8; i++) {
        auto* container = new Container(i*100, i*100, 100, 100, colors[i%3]);
        container->setVisible();
        containers.push_back(container);
    }

    fakeMenus = containers;
}
