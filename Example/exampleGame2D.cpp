#include "exampleGame2D.h"

#include <cassert>
#include <iostream>

ExampleGame2D::ExampleGame2D() : //this is just an application manager. Game2D is an example name.
uiMGR(std::make_unique<UIenv>()),
sceneMGR(std::make_unique<SceneENV>())
{
    initSharedPtx();
    initGame2D();
}

void ExampleGame2D::initGame2D() {
    sceneMGR->init0();
    uiMGR->init0();

    /*PLZFIX: scene->isCurrent doesn't do anything. Also, when input control is given to the scene manager, it loads the generic
     * scene we initialized, not the actual scene. This could probably be solved with a switch case I think.*/



    uiMGR->onRelease = [this](){ sceneMGR->acquireInputControl(); };
    sceneMGR->onRelease = [this](){ uiMGR->acquireInputControl(); };

    uiMGR->acquireInputControl();

    sceneMGR->acquirePlayer(player);
}

void ExampleGame2D::initSharedPtx() {
    uiMGR->setSharedPtx(hd);
    sceneMGR->setSharedPtx(hd);
}

void ExampleGame2D::givePlayer() { //ignore for now
}

void ExampleGame2D::updateGame2D() {
    //TODO: parser places each scene request in its own array. Try to rewrite so that each scene title gets its own array, even if it means writing specifically for scenes

    /*TODO: better for the program if we just assign a current input handler without checking boolean flags every frame.
     * In other words, the code below is wasteful.*/

    if (uiMGR->getInputControlStatus()) { uiMGR->update(); }
    if (sceneMGR->getInputControlStatus()) { sceneMGR->updateCurrentScene(); }

    // else {
    //     std::cerr << "Input Control is Non-Existent." << std::endl;
    //     debugOutro();
    // }
}

void ExampleGame2D::drawGame2D() {
    if (uiMGR->getInputControlStatus()) { uiMGR->draw();}
    if (sceneMGR->getInputControlStatus()) { sceneMGR->drawCurrentScene(); }
}

void ExampleGame2D::debugOutro() {
    int counter = 0;
    int N = 20000;



    while (counter < N) {
        N++;
    }

    exit(27);
}

ExampleGame2D::~ExampleGame2D() = default;
