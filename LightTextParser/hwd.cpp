#include "hwd.h"

#include <iostream>

HWD::HWD() = default;
HWD::~HWD() = default;

std::unique_ptr<Block> HWD::parseFile(const std::string& filename, const std::string& parserKey) {
    // std::ifstream fileSt;
    fileStream.open(filename);

    if (!fileStream.is_open()) {
        std::cerr << "FAILED TO OPEN FILE" << std::endl;
        return std::move(blk);
    }

    std::unordered_map<std::string, std::stack<std::string>> lineInfo; //need to delete all of these after working
    // std::vector<std::string> strings;
    std::string line;

    if (std::getline(fileStream, line)) {
        if (!analyzeParserKey(line, parserKey)) {
            std::cerr << "key does not match file type" << std::endl;
            return std::move(blk);
        }
    }

    while (std::getline(fileStream, line)) {
        if (line.empty()) continue;
        if (line[0] == '/') continue;

        if (line.back() != ';') { /*we only want this check to run for lines containing OBJECT::NAME*/
            std::cerr << "Exit Code[30]: SemiColon required at end of each line for all .hwd files" << std::endl;
            std::cerr << "Illegal Line in" + filename + ":" " " "'" + line + "'" << std::endl;
            exit(30);
        }/*
        TODO: pull type from hwd file AND type from the object calling this function (i.e. ENVui, ENVscene) and
            compare them to make sure we can move forward.
            Then have this function return the BLOCK that contains the information for the calling class to analyze.
        */

        std::string_view sv = line;
        std::cout << line << std::endl;

        auto key = findKeyInLine(sv); /*current problem: when "REQUEST!" is returned */

        if (key.empty()) continue;

        // lineInfo.try_emplace(key);
        blk->labelMap.try_emplace(key);
        sv.remove_prefix(sv.find('=') + 2);

        while (!sv.empty()) { //lastCharOfObjectName refers to length of substring from location to firstCharOfObjectName
            size_t comma = sv.find_first_of(',');

            if (comma != std::string::npos) {
                blk->labelMap[key].emplace_back(sv.substr(0, comma));
            }

            if (comma == std::string::npos && sv.back() == ';') { //checks for end line semicolon when comma does not exist
                sv.remove_suffix(1);
                // strings.emplace_back(sv.substr(0, sv.back()));
                blk->labelMap[key].emplace_back(sv.substr(0, comma));
                // strings.clear();
                break;
            }

            sv.remove_prefix(comma + 2);
        }
    }

    blk->type.clear();

    if (parserKey != "MENU*") { return std::move(blk); }

    //***This should be a separate function

    for (auto& [menuName, buttonLabels] : blk->labelMap) {

        for (auto& label : buttonLabels) {

            std::string_view current = label;

            if (label.find(' ') != std::string::npos) {

                auto space = label.find(' ');
                current = current.substr(0, space);
            }

            blk->identities.emplace_back(current);

        }

        // return std::move(blk);

    }

    //***End separate function
    return std::move(blk);
}

std::string HWD::findKeyInLine(std::string_view sv) { //currently returning empty strings for scene.hwd files
    std::string key;

    if (sv.find("REQUEST!") != std::string::npos) {

        std::string_view s = "REQUEST!";
        sv.remove_prefix(s.size());

        std::string s1 = std::string(sv);

        auto correctedArr = splitProperConditional(s1);

        blk->requests.push_back(correctedArr);
        if (ready) { ready(correctedArr[0], correctedArr[3]); } //for now, should NOT return true for menu.hwd files

        return key;
    }

    if (sv.find('=') != std::string::npos || sv.find("::") != std::string::npos) { //
        auto init = sv.find("::"); //note: there is currently no check for existence of "::"
        auto eq = sv.find('=') != std::string::npos ? sv.find('=') : sv.size();
        auto firstCharOfObjectName = init + 2; //absence of existence check could cause massive issues
        auto lastCharOfObjectName = eq - 1 - firstCharOfObjectName;
            //store value to the right as key, then handle equivalence

        std::string_view s = sv.substr(firstCharOfObjectName, lastCharOfObjectName);
        //we know 's' = "MAIN", so we can convert to string and set as global var.
        //we could call f() here
        current = std::string(s);
        if (guess) { guess(); } //

        if (eq >= sv.size()) {
            blk->labelMap.try_emplace(std::string(s));
            return key;
        }


        sv.remove_prefix(eq + 2);

        key = std::string(s);
        return key;
    }




    return key;
}

std::array<std::string, 2> HWD::split(const std::string& ln, const char c) {
    std::array<std::string, 2> tmp;
    std::string_view sv = ln;

    auto a = ln.find_first_not_of(" \t");
    auto b = ln.find_first_of(c);

    std::string_view p = sv.substr(a, b - a);
    std::string_view q = sv.substr(b + 1, sv.size() - (b+1));

    if (q.back() == ';') { q.remove_suffix(1); }
    else {
        q.remove_suffix(2);
        while (q[q.size()] == ' ') { q.remove_suffix(1); }
    }

    tmp[0] = p;
    tmp[1] = q;

    return tmp;
}

bool HWD::analyzeParserKey(const std::string& keyLine, const std::string &parserKey) {
    std::string_view key = keyLine;
    std::string_view lock = parserKey;

    key = key.substr(1, key.size());
    lock = lock.substr(0, lock.size()-1);

    if (key == lock) {
        blk->type = key;
        return true;
    }

    return false;
}

std::array<std::string, 4> HWD::splitProperConditional(std::string ln, const std::string& operation) {
    if (ln.find(operation) == std::string::npos || ln.empty()) {
        std::array<std::string, 4> nullArr;
        std::cerr << "[WARNING] Failed to split conditional. Returned empty array." << std::endl;
        return nullArr;
    }

    std::erase_if(ln, [](const unsigned char ch) {
        return std::isspace(ch);
    });

    std::string_view sv = ln;

    auto a = sv.find('>') + 1;
    auto b = sv.find(';');

    std::string_view lhs = sv.substr(0, sv.find_first_of('-'));
    std::string_view rhs = sv.substr(a, b-a);

    auto l = splitFromConditional(lhs);
    auto r = splitFromConditional(rhs);

    std::array arr = { std::string(l[0]), std::string(l[1]), std::string(r[0]), std::string(r[1]) };

    return arr;
}

std::array<std::string_view, 2> HWD::splitFromConditional(std::string_view sv) {
    std::array<std::string_view, 2> arr;
    auto delim = sv.find('.');

    arr[0] = sv.substr(0, delim);
    arr[1] = sv.substr(delim + 1, sv.size() - (delim + 1));

    return arr;
}

const std::string& HWD::getCurrent() {
    return current;
}

void HWD::setf(std::function<void()> f) {
    guess = std::move(f);
}

void HWD::setg(std::function<void(const std::string& k, const std::string& v)> g) {
    ready = std::move(g);
}
