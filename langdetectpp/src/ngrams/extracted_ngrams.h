#pragma once

#include <array>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include "utf8.h"
#include "util/circle_array.h"
#include "util/stats.h"

namespace langdetectpp::ngrams
{

class ExtractedNGrams
{
  public:
    ExtractedNGrams(std::vector<std::uint32_t> ones,
                    std::vector<std::tuple<std::uint32_t, std::uint32_t>> twos,
                    std::vector<std::tuple<std::uint32_t, std::uint32_t, std::uint32_t>> threes)
        : oneGrams_(std::move(ones)),
          bigrams_(std::move(twos)),
          trigrams_(std::move(threes)),
          oneGramDist_(0, oneGrams_.size() - 1),
          bigramDist_(0, bigrams_.size() - 1),
          trigramDist_(0, trigrams_.size() - 1) {
    }

    std::uint32_t randomOneGram() {
        return oneGrams_[oneGramDist_.get()];
    }

    std::tuple<std::uint32_t, std::uint32_t> randomBigram() {
        return bigrams_[bigramDist_.get()];
    }

    std::tuple<std::uint32_t, std::uint32_t, std::uint32_t> randomTrigram() {
        return trigrams_[trigramDist_.get()];
    }

    bool empty() {
        return oneGrams_.empty() && bigrams_.empty() && trigrams_.empty();
    }

  private:
    std::vector<std::uint32_t> oneGrams_;
    std::vector<std::tuple<std::uint32_t, std::uint32_t>> bigrams_;
    std::vector<std::tuple<std::uint32_t, std::uint32_t, std::uint32_t>> trigrams_;
    util::UniformIntDist oneGramDist_;
    util::UniformIntDist bigramDist_;
    util::UniformIntDist trigramDist_;
};

}  // namespace langdetectpp::ngrams
