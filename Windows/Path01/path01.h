#ifndef H03_01_PATH01_H
#define H03_01_PATH01_H
#include <unordered_set>
#include <vector>

inline std::unordered_set<std::string> navKeys = {
    "RESUME", "NEW GAME", "BACK", "QUIT", "GOTO MAIN", "GOTO ELSE"
};

inline std::unordered_set<std::string> explicitSceneNames = {

};

//not sure this is the best place to store this set

void runWindow01();

#endif //H03_01_PATH01_H
