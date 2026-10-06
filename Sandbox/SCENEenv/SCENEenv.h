#ifndef H03_01_SCENEENV_H
#define H03_01_SCENEENV_H
#include "../../LightTextParser/hwd.h"
#include "../Scene/SceneList/centerScene.h"
#include "../SceneGraph/sceneGraph.h"


class Player;

class SceneENV {//TODO: UI env must give up 'control' when an in-game scene is active, else UI env has control by default
private:
    Scene* current;
    Scene* preLoadedNextScene;
    std::unordered_map<std::string, std::unique_ptr<Scene>> sceneGraph;
    bool isHandlingInputs;

    std::unique_ptr<Block> blk = nullptr;
    std::shared_ptr<HWD> parser = nullptr;
    const std::string parserKey = "SCENE*";

   Player* player = nullptr;

    std::unordered_map<std::string, std::function<std::unique_ptr<Scene>()>> sceneMakeCalls = {
        {"CENTER",      [] { return std::make_unique<CenterScene>(); }}
    };

public: //initially meant to handle scene switching for non-ui dominated scenes
    std::function<void()> onRelease;

    SceneENV();
    ~SceneENV();

    void init0();
    void acquirePlayer(const std::shared_ptr<Player>& plyr);
    void assignPlayer();
    void updateCurrentScene();
    void drawCurrentScene();

    void setSharedPtx(std::shared_ptr<HWD> ptx);
    void acquireInputControl();
    void releaseInputControl();

    bool getInputControlStatus();



    std::unique_ptr<Scene> makeExplicitScene(const std::string& expSceneType);
};

#endif //H03_01_SCENEENV_H
