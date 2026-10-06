#ifndef H03_01_LIGHTTEXTPARSER_H
#define H03_01_LIGHTTEXTPARSER_H
#include <cstdio>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> parseLite(const std::string& filename);
std::array<std::string, 2> split(const std::string& ln, char c);
std::array<std::string, 4> splitConditional(std::string_view ln, std::string_view operation);

std::vector<std::string> parseScenesHWD(const std::string& filename);
std::vector<std::string> parseSceneRequests();

void parserTest01(std::ifstream file, const std::string& line);

#endif //H03_01_LIGHTTEXTPARSER_H
