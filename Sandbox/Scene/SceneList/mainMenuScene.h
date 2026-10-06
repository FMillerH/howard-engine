#ifndef H03_01_MAINMENUSCENE_H
#define H03_01_MAINMENUSCENE_H
#include "../scene.h"

class Menu;

class MainMenu : public Scene {
private:
    Menu* menu;

public:
    MainMenu();
    explicit MainMenu(std::string name);
    ~MainMenu() override;

    void runScene() override;
    void drawScene() override;
};

#endif //H03_01_MAINMENUSCENE_H
