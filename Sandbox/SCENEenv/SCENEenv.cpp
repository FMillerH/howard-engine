#include "SCENEenv.h"

#include <utility>

#include "../Scene/SceneList/centerScene.h"

SceneENV::SceneENV() :
current(nullptr),
preLoadedNextScene(nullptr),
isHandlingInputs(false)
{
    //init0(); leave this commented out
}

//setf: adds name of scene as key, then creates a GENERIC scene with that name
//setg: adds scene connection to graph

void SceneENV::init0() {

    parser->setf(
        [this]() { sceneGraph[parser->getCurrent()] = makeExplicitScene(parser->getCurrent()); } //we can call our new class method
    );

    parser->setg(
        [this](const std::string& key, const std::string& value) { sceneGraph[key]->addConnection(value); }
    );

    blk = parser->parseFile("../scene.hwd", parserKey);//blk is no longer necessary
}

void SceneENV::acquirePlayer(const std::shared_ptr<Player>& plyr) {
    player = plyr.get();
}

void SceneENV::assignPlayer() {
}

void SceneENV::updateCurrentScene() { current->runScene(); }

void SceneENV::drawCurrentScene() { current->drawScene(); }

void SceneENV::setSharedPtx(std::shared_ptr<HWD> ptx) { parser = std::move(ptx); }

void SceneENV::acquireInputControl() {
    if (current == nullptr) {
        current = sceneGraph["CENTER"].get(); //after NEW GAME is clicked
        current->player = player;
    }

    isHandlingInputs = true;
}//must set an active scene

void SceneENV::releaseInputControl() { isHandlingInputs = false; }

bool SceneENV::getInputControlStatus() { return isHandlingInputs; }

std::unique_ptr<Scene> SceneENV::makeExplicitScene(const std::string& expSceneType) {

    if (auto it = sceneMakeCalls.find(expSceneType); it != sceneMakeCalls.end()) {
        return it->second();
    }

    return std::make_unique<Scene>(expSceneType);
}

SceneENV::~SceneENV() = default;
