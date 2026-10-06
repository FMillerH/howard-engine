#include "menu.h"

Menu::Menu() :
Container(0, 0, 0, 0, RED),
preSelectedButton(nullptr),
next(nullptr),
menuIsActive(false),
numButtons(0)
{
}

Menu::Menu(float x, float y, float width, float height) :
Container(x, y, width, height, RED),
preSelectedButton(nullptr),
next(nullptr),
menuIsActive(false),
numButtons(0)
{
}

void Menu::setMenuName(const std::string& str) { name = str; }

std::string Menu::getMenuName() { return name; }

void Menu::drawContainer() const {
    if (isVisible) {
        DrawRectangleLinesEx(body, 1.0f, RED);

        for (Button* button : buttons) {
            button->drawContainer();
        }
    }
}

void Menu::addButton() {
    auto button = new Button();
    buttons.push_back(button);

    button->body.x = body.x;
    button->body.y = body.y;

    if (isVisible) {
        button->setVisible();
    }

    //store warning about button size if 0

    if (!button->label.empty()) {
        buttonMap[button->label] = button;
    }
}

void Menu::addButton(float x, float y, float width, float height, Color color) {
    auto button = new Button(x, y, width, height, color);
    buttons.push_back(button);

    if (isVisible) {
        button->setVisible();
    }

    if (!button->label.empty()) {
        buttonMap[button->label] = button;
    }
}

void Menu::addExistingButton(Button* button) {
    buttons.push_back(button);

    if (!button->label.empty()) {
        buttonMap[button->label] = button;
    }
}

void Menu::setVisible() {
    if (!isVisible) {
        isVisible = true;

        for (Button* button : buttons) {
            button->setVisible();
        }

        menuIsActive = true;
    }
}

void Menu::setInvisible() {
    if (isVisible) {
        isVisible = false;

        for (Button* button : buttons) {
            button->setInvisible();
        }

        menuIsActive = false;
    }
}

void Menu::setNumButtons(int n) { //does not add buttons to vector
    numButtons = n;
}

void Menu::scanButtonsForCollision(Vector2 mouse) {
    for (Button* button : buttons) {

        if (CheckCollisionPointRec(mouse, button->body)) {
            setPreSelectedButton(button);
            break;
        }
    }
}

Button* Menu::setPreSelectedButton(Button* button) {
    if (button == nullptr) { return nullptr; }

    if (button == preSelectedButton) { return preSelectedButton; }

    if (preSelectedButton != nullptr) {
        preSelectedButton->setNotHovering();
    }

    preSelectedButton = button;
    preSelectedButton->setHovering();

    return preSelectedButton;
}

Button* Menu::getPreSelectedButton() { return preSelectedButton; }

Button* Menu::getButtonFromLabel(const std::string& label) {
    if (!buttonMap.contains(label)) { return nullptr; }

    return buttonMap[label];
}

void Menu::clearPreSelectedButton() {
    if (preSelectedButton != nullptr) {
        preSelectedButton->setNotHovering();
        preSelectedButton = nullptr;
    }
}

Menu* Menu::setNext(Menu* menu) { return next = menu; }

Menu* Menu::getNext() { return next; }

Menu::~Menu() {
    for (Button* button : buttons) {
        delete button;
    }
}