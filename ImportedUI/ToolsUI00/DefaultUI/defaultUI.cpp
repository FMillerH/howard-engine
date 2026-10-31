#include "defaultUI.h"

#include "../Placer/placer.h"

std::unique_ptr<Menu> DefaultUI::buildDefaultMenu(const std::string& name, std::vector<std::string>& labels, Vector4 dimensions) {
    if (labels.empty()) {

        labels = {
            "YOU", "DIDN'T", "STORE", "LABELS", "IDIOT"
        };
    }

    if (labels[0].find("REQUEST!") != std::string::npos) {
        auto requestMenu = std::make_unique<Menu>();

        std::string line = labels[0];
        std::string tag = "REQUEST!";
        labels[0].erase(0, tag.size() + 1);

        return requestMenu;
    }

    auto defaultMenu = std::make_unique<Menu>();

    if (dimensions.w == 0 || dimensions.z == 0) {
        defaultMenu->body = { .x = 100, .y = 100, .width = 600, .height = 400 };
    }
    else { defaultMenu->body = { .x = dimensions.x, .y = dimensions.y, .width = dimensions.w, .height = dimensions.z }; }

    defaultMenu->setNumButtons(static_cast<int>(labels.size()));
    defaultMenu->setMenuName(name);


    std::vector<Rectangle> bodies = Placer::placeElements(defaultMenu->body, 5.0f, defaultMenu->numButtons);

    for (int i = 0; i < defaultMenu->numButtons; i++) { //must change all buttons to smart pointers in long run
        auto button = new Button();
        button->body = bodies[i];
        button->setLabel(labels[i]);
        button->setFillTypeToHollow();
        defaultMenu->addExistingButton(button);
    }


    return defaultMenu;
}