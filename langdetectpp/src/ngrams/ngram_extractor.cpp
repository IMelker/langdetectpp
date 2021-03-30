#include "ngrams/ngram_extractor.h"

namespace langdetectpp::ngrams
{

NGramExtractor::NGramExtractor(const std::string &text)
    : textRef_(text) {
    iter_ = textRef_.c_str();
    end_ = iter_ + textRef_.size();
}

bool NGramExtractor::good() { return (iter_ != end_); }

bool NGramExtractor::advance() {
    if (!good()) {
        return false;
    }
    std::uint32_t cPoint = utf8::next(iter_, end_);
    codePoints_.push(cPoint);
    return true;
}

ExtractedNGrams NGramExtractor::extract() {
    for (size_t i = 0; i < 3; i++) {
        if (!advance()) {
            return ExtractedNGrams(std::move(oneGrams_), std::move(bigrams_), std::move(trigrams_));
        }
    }
    oneGrams_.emplace_back(codePoints_.getOne());
    bigrams_.emplace_back(codePoints_.getTwo());
    trigrams_.emplace_back(codePoints_.getThree());
    while (advance()) {
        oneGrams_.emplace_back(codePoints_.getOne());
        bigrams_.emplace_back(codePoints_.getTwo());
        trigrams_.emplace_back(codePoints_.getThree());
    }
    return ExtractedNGrams(std::move(oneGrams_), std::move(bigrams_), std::move(trigrams_));
}

}  // namespace langdetectpp::ngrams
