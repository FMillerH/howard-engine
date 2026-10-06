#include "scene.h"

#include <iostream>
#include <utility>

#include "raylib.h"
#include "../../Example/player.h"

Scene::Scene() :
isCurrent(false),
preLoadedCompanion(nullptr)
{
}

Scene::Scene(std::string name) :
isCurrent(false),
preLoadedCompanion(nullptr),
name (std::move(name))
{
}

void Scene::runScene() {
    player->movePlayer();
}

void Scene::drawScene() {

}

Scene* Scene::setSceneAsCurrent() {
    if (!isCurrent) { isCurrent = true; }
    return this;
}

Scene* Scene::removeSceneAsCurrent() {
    if (isCurrent) { isCurrent = false; }
    return this;
}

void Scene::addConnection(const std::string& sceneName) {
    connections.insert(sceneName);
}

void Scene::endScene() { std::cout << "SCENE ENDED" << std::endl; }

Scene::~Scene() = default;
