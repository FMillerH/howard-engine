#include "uie.h"

#include <iostream>

#include "../../LightTextParser/lightTextParser.h"

UIenv::UIenv() :
isHandlingInputs(true),
currentMenu(nullptr),
mouse()
{
    initializeNavigationTable();
    //init0();

    controller.initKeyBindings(262, [](){ std::cout << "right" << std::endl; });
    controller.initKeyBindings(263, [](){ std::cout << "left" << std::endl; });
    controller.initKeyBindings(264, [](){ std::cout << "down" << std::endl; });
    controller.initKeyBindings(265, [](){ std::cout << "up" << std::endl; });
}

void UIenv::init0() {
    auto hwd = std::make_unique<HWD>();
    blk = hwd->parseFile("../menu.hwd", "MENU*");
    hwd.reset();

    for (auto& [name, labels] : blk->labelMap) {
        menuMap.try_emplace(name, DefaultUI::buildDefaultMenu(name, labels));
        labels.clear();
    }

    if (!blk->requests.empty()) { analyzeRequests(); }

    menuStack.push(menuMap["MAIN"].get());
    currentMenu = menuStack.top();

    currentMenu->setVisible();
}

void UIenv::setSharedPtx(std::shared_ptr<HWD> ptx) { parser = std::move(ptx); }

void UIenv::update() {
    mouse = GetMousePosition();

    if (currentMenu == nullptr) {

        if (menuMap.empty()) {
            std::cerr << "Error Code [35]: UIenv.menus does not contain an existing menu\n" << std::endl;
            exit(35);
        }

        exit(34);
    }

    if (CheckCollisionPointRec(mouse, currentMenu->body)) {
        currentMenu->scanButtonsForCollision(mouse);
    }

    else { currentMenu->clearPreSelectedButton(); }

    processInput(); //needs to be running regardless of mouse position
}

void UIenv::draw() {
    currentMenu->drawContainer();
}

void UIenv::processInput() {
    if (IsMouseButtonPressed(0)) {

      // __builtin_debugtrap(); //this will CRASH the program if it is not commented out

        if (currentMenu->getPreSelectedButton() == nullptr) { return; } /* wrong. well... actually this is fine, but the rest is wrong */

        if (auto it = navigationTable.find(currentMenu->getPreSelectedButton()->label); it != navigationTable.end()) { //using the label is what is causing this thing to break
            it->second();
        } else { navigationTable.find("GOTO ELSE")->second(); }


        // if (currentMenu->getPreSelectedButton()->connectsToMenu) { /* also very wrong */
        //     /* note: if a button connects to a menu, it is not allowed to connect to a scene.
        //      * this needs to be expressed in the code.
        //      * as of now, a button is allowed to connect to both, which will cause issues. */
        //
        //     // std::cout << menuMap[currentMenu->getPreSelectedButton()->connectionName]->getMenuName() << std::endl;
        //
        //     auto nextMenu = menuMap[currentMenu->getPreSelectedButton()->connectionName].get();
        //     currentMenu->setInvisible();
        //     currentMenu = nextMenu;
        //     currentMenu->setVisible();
        // }

       // if (currentMenu->getPreSelectedButton()->getConnectsToScene()) {
            /* ui should signal via lambda function that it is releasing control of input processing.
             * when parent class sees this, it assigns input processing control to the current scene until the scene
             * has ended or the game has been paused. */

            /* this contradicts the premise that menus and scenes are inherently different because we have established
             * that the main menu is itself a scene. */
        //}
    }

    if (IsMouseButtonPressed(1)) {
        std::cout << "button info here" << std::endl;

        process();

        std::cout << currentMenu->getPreSelectedButton()->getConnectsToMenu() << std::endl;
    }
}

void UIenv::process() {
    for (int i = 0; i < 1000000; i++) {
        std::cout << i << std::endl;
    }
}

void UIenv::analyzeRequests() {

    /* TODO: unfinished--assumes last element in each array is always connected to something. This has been removed,
        * meaning that either biconditional needs to be updated, or arrays should only contain the three relevant items
        * rather than the current four. The three element array is probably the better option, since we would only need
        * to connect two menus if a 'back' button is involved (at least for now), which is
        *  already handled via the menu stack. Just hasn't been hardcoded onto the 'back' button type.
     */

    for (const auto& arr : blk->requests) {
        auto menuName1 = arr[0];
        auto menuName2 = arr[2];

        Menu* menu = menuMap[menuName1].get();
        Menu* next = menuMap[menuName2].get();

        menu->getButtonFromLabel(arr[1])->setConnectsToMenu(next->getMenuName());
        next->getButtonFromLabel(arr[3])->setConnectsToMenu(menu->getMenuName());

        menu->setNext(next);
    }
}

Menu* UIenv::pullMenu(const std::string& menuName) {
    return menuMap[menuName].get();
}

void UIenv::goForward() {
    if (currentMenu->getNext() == nullptr || !currentMenu->getPreSelectedButton()->getConnectsToMenu()) {
        std::cerr << "button does not connect to a menu" << std::endl;
        return;
    }


    /*PLZFIX: TEST_B2, despite not being assigned a menu, is able to connect to MENU::SELECT because its name does not
     * exist in the navigation table, so it defaults to GOTO ELSE. It's the MENU that's connected to MENU::SELECT, not
     * the button. This is not a program-breaking issue, but it proves that there is too much bullshit code laying
     * around. */


    menuStack.push(currentMenu->getNext());
    currentMenu = menuStack.top();
    currentMenu->setVisible();
}

void UIenv::goBack() {
    menuStack.pop();
    currentMenu = menuStack.top();
}

void UIenv::acquireInputControl() {
    isHandlingInputs = true;
}

void UIenv::releaseInputControl() {
    menuStack = {};
    isHandlingInputs = false;

    if (onRelease) { onRelease(); }
}

bool UIenv::getInputControlStatus() { return isHandlingInputs; }

Menu* UIenv::stackTest() {
    return menuStack.top();
}

Menu* UIenv::getCurrentMenuTest() {
    return currentMenu;
}

void UIenv::initializeNavigationTable() {
/* current problem: the table below is meant to use button navigation keys, not the labels themselves,
 * meaning that we need to find a way to assign navKeys dynamically, preferably without messing with the parser. */

    navigationTable = {
        {"RESUME",      [this]()    { releaseInputControl(); currentMenu->setInvisible(); }},
        {"NEW GAME",    [this]()    { releaseInputControl(); }},
        {"LOAD GAME",   []()        { std::cerr << "MENU::LOAD does not yet exist" << std::endl; }},
        {"QUIT",        []()        { exit(5); }},
        {"BACK",        [this]()    { goBack(); }},
        {"GOTO MAIN",   [this]()    { pullMenu("MAIN"); }},
        {"GOTO ELSE",   [this]()    { goForward(); }}
    };

    navigationTableTEST = {

    };
}

UIenv::~UIenv() = default;
