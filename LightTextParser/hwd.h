#ifndef H03_01_HWD_H
#define H03_01_HWD_H
#include <fstream>
#include <string>

struct Block {
    std::string type;
    std::unordered_map<std::string, std::vector<std::string>> labelMap; //key = menu name, value = menu button labels
    std::vector<std::string> identities; //truncates multi-word labels to single-word and assigns ID
    std::vector<std::array<std::string, 4>> requests;
};

class HWD {
private:
    std::unique_ptr<Block> blk = std::make_unique<Block>();
    std::ifstream fileStream;
    std::string findKeyInLine(std::string_view sv);

    std::function<void(std::string str)> onSoloParsed;
    std::function<void()> guess;
    std::function<void(const std::string& k, const std::string& v)> ready;
    std::string current;



public:
    HWD();
    ~HWD();

    std::unique_ptr<Block> parseFile(const std::string& filename, const std::string& parserKey);
    std::array<std::string, 2> split(const std::string& ln, char c);
    std::array<std::string, 4> splitConditional(std::string_view ln, std::string_view operation);
    bool analyzeParserKey(const std::string& keyLine, const std::string& parserKey);

    std::array<std::string_view, 2> splitFIX(std::string_view sv, char c);

    void setf(std::function<void()> f);
    void setg(std::function<void(const std::string& k, const std::string& v)> g);

    const std::string& getCurrent();

    void assignIDtoLabels();

};

#endif //H03_01_HWD_H
