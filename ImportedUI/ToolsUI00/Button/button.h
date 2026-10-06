#ifndef H03_01_BUTTON_H
#define H03_01_BUTTON_H

#include <functional>
#include <string>

#include "raylib.h"
#include "../Container/container.h"

class Button : public Container {
private:
    std::string navigationKey;


public:
    Color defaultFill;
    Color colorFill;
    Color hoverFill;
    std::string label;
    bool isHollow;
    bool hover;
    bool connectsToMenu;
    bool connectsToScene;
    std::string connectionName;

    std::function<void()> onClick;
    std::function<int()> onClickTwo;



    Button();
    Button(float x, float y, float width, float height, Color color);
    ~Button() override;

    void drawContainer() const override;
    void setOnClick(const std::function<void()> &callback);
    void setOnClickTwo(const std::function<int()> &callback);
    void setLabel(const std::string &buttonLabel);

    std::string setButtonNavigationKey(const std::string& navKey);

    void setHovering();
    void setNotHovering();
    void setFillTypeToHollow();
    void setFillTypeToFill();
    void setFitToParent(Container* parent, float spacing);
    bool setConnectsToMenu(const std::string& name);
    bool getConnectsToMenu();
    bool setConnectsToScene(const std::string& name);
    bool getConnectsToScene();
};

#endif //H03_01_BUTTON_H