#ifndef H03_01_DEFAULTUI_H
#define H03_01_DEFAULTUI_H

#include "../Container/container.h"
#include "../Button/button.h"
#include "../Menu/menu.h"


class DefaultUI {
public:
    
    static std::unique_ptr<Menu> buildDefaultMenu(const std::string& name, std::vector<std::string>& labels);

};

#endif //H03_01_DEFAULTUI_H