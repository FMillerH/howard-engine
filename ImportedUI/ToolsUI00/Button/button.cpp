#include "button.h"

Button::Button() :
Container(0,0,0,0, RED),
defaultFill(SKYBLUE),
colorFill(SKYBLUE),
hoverFill(RED),
isHollow(false),
hover(false),
connectsToMenu(false),
connectsToScene(false)
{
}

Button::Button(float x, float y, float width, float height, Color color) :
Container(x, y, width, height, color),
defaultFill(color),
colorFill(color),
hoverFill(RED),
isHollow(false),
hover(false),
connectsToMenu(false),
connectsToScene(false)
{
}

void Button::drawContainer() const {
    if (isVisible) {

        if (!isHollow) { DrawRectangleRec(body, colorFill); }

        else { DrawRectangleLinesEx(body, 1.0f, colorFill); }

        if (!label.empty()) { DrawText(label.c_str(), body.x + 5.0f, body.y + 5.0f, 36, WHITE); }
    }
}

void Button::setOnClick(const std::function<void()> &callback) {
    onClick = callback;
}

void Button::setOnClickTwo(const std::function<int()> &callback) {
    onClickTwo = callback;
}

void Button::setLabel(const std::string &buttonLabel) { //this should return and store the label
    label = buttonLabel;
}

std::string Button::setButtonNavigationKey(const std::string &navKey) {
    return navigationKey = navKey;
}

void Button::setHovering() {
    if (!hover) {
        hover = true;
        colorFill = hoverFill;
    }

    // printf("hovering: true\n");
}

void Button::setNotHovering() {
    if (hover) {
        hover = false;
        colorFill = defaultFill;
    }

    // printf("hovering: false\n");
}

void Button::setFillTypeToHollow() {
    if (!isHollow) {
        isHollow = true;
    }
}

void Button::setFillTypeToFill() {
    if (isHollow) {
        isHollow = false;
    }
}

void Button::setFitToParent(Container* parent, float spacing) {
   //decide later if this function is useful
}

bool Button::setConnectsToMenu(const std::string& name) { //this is only meant to be used by UIE at startup
    if (!connectsToMenu) {
        connectionName = name;
        return connectsToMenu = true;
    }

    return connectsToMenu = false;
}

bool Button::getConnectsToMenu() { return connectsToMenu; }

bool Button::setConnectsToScene(const std::string &name) {
    if (!connectsToScene) {
        connectionName = name;
        return connectsToScene = true;
    }
}

bool Button::getConnectsToScene() { return connectsToScene; }

Button::~Button() = default;
