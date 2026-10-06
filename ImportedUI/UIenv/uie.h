#ifndef H03_01_UIE_H
#define H03_01_UIE_H
#include <stack>

#include "../../Controller/controller.h"
#include "../../LightTextParser/hwd.h"
#include "../ToolsUI00/DefaultUI/defaultUI.h"

class UIenv {
private:
    bool isHandlingInputs;

    Controller controller;

    std::unique_ptr<Block> blk = nullptr;
    std::shared_ptr<HWD> parser = nullptr;
    const std::string parserKey = "MENU*";

    std::unordered_map<std::string, std::unique_ptr<Menu>> menuMap;
    std::unordered_map<std::string, std::function<void()>> navigationTable;
    std::unordered_map<std::string, std::function<void()>> navigationTableTEST;

    Menu* currentMenu;
    std::stack<Menu*> menuStack;

    void initializeNavigationTable();

public:
    Vector2 mouse;
    std::function<void()> onRelease;

    UIenv();
    ~UIenv();

    void init0();
    void setSharedPtx(std::shared_ptr<HWD> ptx);
    void update();
    void draw();
    void processInput();

    void process();

    // void manageState();
    Menu* pullMenu(const std::string& menuName);
    void goForward();
    void goBack();
    void releaseInputControl();
    void acquireInputControl();

    bool getInputControlStatus();

    Menu* stackTest();
    Menu* getCurrentMenuTest();


    void analyzeRequests();
};

#endif //H03_01_UIE_H
