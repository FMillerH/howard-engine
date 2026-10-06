#ifndef H03_01_SCENE_H
#define H03_01_SCENE_H
#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

class Player;

class Scene { //refer to h05 to see how subscenes work and the information they contain
private:
    bool isCurrent; //this doesn't really do anything right now
    Scene* preLoadedCompanion;
    std::unordered_set<std::string> connections;

//IDEA: write general scripts and apply dynamically
    //OR hardcode all unique scenes and let ENV instantiate THOSE classes rather than general scenes

public:
    std::string name;
    std::function<void()> onSceneEnd;
    Player* player = nullptr;

    Scene();
    explicit Scene(std::string name);

    virtual ~Scene();

    void virtual runScene();
    void virtual drawScene();
    void virtual endScene();
    Scene* setSceneAsCurrent();
    Scene* removeSceneAsCurrent(); //maybe return the address of replacement scene instead of returning void

    void addConnection(const std::string& sceneName);
};

#endif //H03_01_SCENE_H
