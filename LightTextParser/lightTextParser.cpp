#include "lightTextParser.h"
#include <fstream>
#include <iostream>

std::vector<std::vector<std::string>> parseLite(const std::string &filename) { /***************************************/

    std::ifstream file;
    file.open(filename);

    std::vector<std::vector<std::string>> all;

    if (!file.is_open()) {
        //error
        return all;
    }

    std::vector<std::string> strings;
    std::string line;

    while (std::getline(file, line)) {

        if (line.empty()) continue;
        if (line[0] == '/') continue;

        if (line.back() != ';') { /*we only want this check to run for lines containing OBJECT::NAME*/

            std::cerr << "Exit Code[30]: SemiColon required at end of each line for all .hwd files" << std::endl;
            std::cerr << "Illegal Line in" + filename + ":" " " "''" + line + "''" << std::endl;
            exit(30);
        }

        if (line[0] == '/') continue;

        std::string_view sv = line;

        std::cout << line << std::endl;

        while (!sv.empty()) {
            if (sv.find('=') != std::string::npos) {
                auto init = sv.find("::");
                auto eq = sv.find('=');
                auto a = init + 2;
                auto b = eq - 1 - a;
                //store value to the right as key, then handle equivalence
                std::string_view s = sv.substr(a, b);
                strings.emplace_back(s);
                sv.remove_prefix(eq + 2);
                continue;
            }

            size_t comma = sv.find_first_of(',');

            if (comma != std::string::npos) { //checks if comma exists
                strings.emplace_back(sv.substr(0, comma));
            }

            if (comma == std::string::npos && sv.back() == ';') { //checks for end line semicolon when comma does not exist
                sv.remove_suffix(1);
                strings.emplace_back(sv.substr(0, sv.back()));
                all.emplace_back(strings);
                strings.clear();
                break;
            }
            sv.remove_prefix(comma + 2);
        }
    }
    return all; /*****************************************************************************************************/
}

std::array<std::string, 2> split(const std::string& ln, const char c) {
    std::array<std::string, 2> tmp;
    std::string_view sv = ln;

    auto a = ln.find_first_not_of(" \t");
    auto b = ln.find_first_of(c);

    std::string_view p = sv.substr(a, b - a);
    std::string_view q = sv.substr(b + 1, sv.size() - (b+1));

    if (q.back() == ';') { q.remove_suffix(1); }

    tmp[0] = p;
    tmp[1] = q;

    return tmp;
}

std::array<std::string, 4> splitConditional(std::string_view ln, std::string_view operation) {
    if (ln.find(operation) == std::string::npos) {
        std::cerr << "WARNING: Failed to split conditional." << std::endl;
        return {};
    }

    std::array<std::string, 4> tmp;
    std::string_view sv = ln;

    if (operation == "->") { //we already checked for this

        auto delim = sv.find_first_of('-');
        auto begin = sv.find_first_not_of(' ');
        auto second = sv.find_first_of('>');

        if (sv[second + 1] == ' ') { second++; }

        std::string_view lhs = sv.substr(begin, sv.size() - (delim - 1));
        std::string_view rhs = sv.substr(second, sv.size() - (delim + 1));

        auto l = split(static_cast<std::string>(lhs), '.');
        auto r = split(static_cast<std::string>(rhs), '.');

        tmp = { l[0], l[1], r[0], r[1] };
        return tmp;

    }

    if (tmp[0].empty()) {
        std::cerr << "FATAL ERROR: splitConditional() is INCOMPLETE" << std::endl;
        exit(909);
    }

    return tmp;
}

std::vector<std::string> parseScenesHWD(const std::string &filename) {
    std::vector<std::string> tmp = {};

    std::ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        //error
        return tmp;
    }

    std::vector<std::string> strings;
    std::string line;

    if (std::getline(file, line)) {

        if (line.find("SCENES*") == std::string::npos) {
            std::cerr << "SYNTAX ERROR: [error]" << std::endl;
        }
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == '/') continue;

        if (line.find("REQUEST!") != std::string::npos) {
            //special function that builds scene graph
            std::cout << "REQUEST IDENTIFIED" << std::endl;
            break;
        }

        if (line.back() != ';') { /*we only want this check to run for lines containing OBJECT::NAME*/

            std::cerr << "Exit Code[30]: SemiColon required at end of each line for all .hwd files" << std::endl;
            std::cerr << "Illegal Line in" + filename + ":" " " "''" + line + "''" << std::endl;
            exit(30);
        }

        if (line[0] == '/') continue;

        std::string_view sv = line;

        std::cout << line << std::endl;

    }

    return tmp;
}

void parserTest01() {

}