#ifndef H03_01_SCENEGRAPH_H
#define H03_01_SCENEGRAPH_H
#include <unordered_map>
#include "../Scene/scene.h"

class SceneGraph {//TODO: This doesn't need to be its own class. It should exist within the sceneENV class.
public:
    std::unordered_map<std::string, std::unique_ptr<Scene>> sceneMap;

    SceneGraph();
    ~SceneGraph();
};
#endif //H03_01_SCENEGRAPH_H
