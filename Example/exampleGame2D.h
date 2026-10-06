#ifndef H03_01_EXAMPLEGAME2D_H
#define H03_01_EXAMPLEGAME2D_H

#include "player.h"
#include "../ImportedUI/UIenv/uie.h"
#include "../Sandbox/SCENEenv/SCENEenv.h"

class ExampleGame2D {
private:
    std::unique_ptr<UIenv> uiMGR;
    std::unique_ptr<SceneENV> sceneMGR;
    std::shared_ptr<HWD> hd = std::make_shared<HWD>();
    std::shared_ptr<Player> player = std::make_shared<Player>();

public:
    ExampleGame2D();
    ~ExampleGame2D();

    void initSharedPtx();
    void givePlayer();

    void initGame2D();
    void updateGame2D();
    void drawGame2D();

    void debugOutro();

};

#endif //H03_01_EXAMPLEGAME2D_H
