#include "mainMenuScene.h"

#include <utility>

#include "raylib.h"

MainMenu::MainMenu() :
Scene("MAIN"),
menu(nullptr)
{
}

MainMenu::MainMenu(std::string name) :
Scene(std::move(name)),
menu(nullptr)
{
}

MainMenu::~MainMenu() = default;

void MainMenu::runScene() {
    if (IsMouseButtonPressed(0) || IsMouseButtonPressed(1)) {
        //process()
    }
}

void MainMenu::drawScene() {

}
