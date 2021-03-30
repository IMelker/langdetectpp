#include <cassert>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

#include <langdetectpp/langdetectpp.h>

namespace fs = std::filesystem;
using langdetectpp::Language;

int main() {
    std::vector<std::pair<std::string, Language>> files = {
        {"ar_from_wikipedia.txt", Language::AR},
        {"en_from_wikipedia.txt", Language::EN},
        {"ru_from_wikipedia.txt", Language::RU},
        {"de_from_wikipedia.txt", Language::DE},
        {"fr_from_wikipedia.txt", Language::FR},
        {"es_from_wikipedia.txt", Language::ES}
        };

    std::size_t maxLen = 0;
    for (auto &elem : files) {
        auto fname = elem.first;
        if (fname.size() > maxLen) {
            maxLen = fname.size();
        }
    }
    auto detector = langdetectpp::Detector::create();

    fs::path basePath = fs::canonical("../../tests/text");
    for (auto &elem : files) {
        std::string fname = elem.first;
        fs::path filePath = basePath / fname;

        std::ifstream ifs(filePath.string());
        std::string data(std::istreambuf_iterator<char>{ifs}, {});

        auto lang = detector->detect(data);

        std::ostringstream logLine;
        logLine << fname;
        for (std::size_t i = fname.size(); i < maxLen; i++) {
            logLine << " ";
        }
        std::cout << logLine.str() << "  ->  "
                  << langdetectpp::toLongName(lang) << "["
                  << langdetectpp::toShortName(lang) << "]" << std::endl;
        assert(elem.second == lang);
    }
}
