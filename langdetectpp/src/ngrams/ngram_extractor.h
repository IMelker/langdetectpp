#pragma once
#include <string>
#include <tuple>
#include <vector>
#include "utf8.h"
#include "ngrams/extracted_ngrams.h"
#include "util/circle_array.h"

namespace langdetectpp::ngrams
{

class NGramExtractor
{
public:
    explicit NGramExtractor(const std::string& text);

    bool good();
    ExtractedNGrams extract();

  protected:
    bool advance();

    const char* iter_ = nullptr;
    const char* end_ = nullptr;
    const std::string& textRef_;
    util::CircleArray<std::uint32_t, 3> codePoints_;
    std::vector<std::uint32_t> oneGrams_;
    std::vector<std::tuple<std::uint32_t, std::uint32_t>> bigrams_;
    std::vector<std::tuple<std::uint32_t, std::uint32_t, std::uint32_t>> trigrams_;
};

}  // namespace langdetectpp::ngrams
