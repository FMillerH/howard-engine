#ifndef H03_01_MENU_H
#define H03_01_MENU_H
#include <vector>

#include "../Container/container.h"
#include "../Button/button.h"

class Menu : public Container {
private:
    std::string name;
    Button* preSelectedButton;
    Menu* next;
    std::unordered_map<std::string, Button*> buttonMap; //convert to unique pointers when able

public:
    bool menuIsActive;
    int numButtons;
    std::vector<Button*> buttons;

    Menu();
    Menu(float x, float y, float width, float height);
    ~Menu() override;

    void setMenuName(const std::string& str);
    std::string getMenuName();
    void drawContainer() const override;
    void addButton();
    void addButton(float x, float y, float width, float height, Color color);
    void addExistingButton(Button* button);
    void setVisible() override;
    void setInvisible() override;
    void setNumButtons(int n);
    void scanButtonsForCollision(Vector2 mouse);
    Button* setPreSelectedButton(Button* button);
    Button* getPreSelectedButton();
    Button* getButtonFromLabel(const std::string& label);
    void clearPreSelectedButton();
    Menu* setNext(Menu* menu);
    Menu* getNext();
};

#endif //H03_01_MENU_H