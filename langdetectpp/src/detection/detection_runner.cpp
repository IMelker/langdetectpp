#include <vector>
#include "detection/detection_runner.h"

namespace langdetectpp::detection
{

constexpr double CONV_THRESHOLD = 0.99999;
constexpr std::size_t BASE_FREQ = 10000;
constexpr std::size_t ITERATION_LIMIT = 1000;

DetectionRunner::DetectionRunner(std::shared_ptr<profiles::ProfileGroup> profGroup,
                                 ngrams::ExtractedNGrams &extracted)
    : profileGroup_(std::move(profGroup)), textNGrams_(extracted) {
    for (std::size_t i = 0; i < profileGroup_->profiles.size(); i++) {
        langScores_.push_back(0.0);
    }
}

Language DetectionRunner::getBestScore() {
    double maxScore = 0.0;
    std::size_t maxIndex = 0;
    for (std::size_t i = 0; i < langScores_.size(); i++) {
        auto score = langScores_[i];
        if (score > maxScore) {
            maxScore = score;
            maxIndex = i;
        }
    }
    auto winningLang = profileGroup_->profiles.at(maxIndex);
    return winningLang->getLanguage();
}

Language DetectionRunner::detect() {
    const std::size_t numTrials = 7;
    for (std::size_t trialN = 0; trialN < numTrials; trialN++) {
        alpha_.warble();
        auto probs = runTrial();
        for (std::size_t j = 0; j < langScores_.size(); j++) {
            double divisor = static_cast<double>(trialN);
            if (divisor <= 0) {
                divisor = 1.0;
            }
            double toAdd = (probs[j] / divisor);
            langScores_[j] += toAdd;
        }
    }
    return getBestScore();
}

std::vector<double> *DetectionRunner::getLanguageScoresForRandomNGramOrNull() {
    std::size_t ngLen = ngramLengthDist_.get();
    std::vector<double> *langWordScores = nullptr;
    if (ngLen == 1) {
        auto ng = textNGrams_.randomOneGram();
        auto found = profileGroup_->oneGramWeights.find(ng);
        if (found != profileGroup_->oneGramWeights.end()) {
            langWordScores = &found->second;
        }
    } else if (ngLen == 2) {
        auto ng = textNGrams_.randomBigram();
        auto found = profileGroup_->bigramWeights.find(ng);
        if (found != profileGroup_->bigramWeights.end()) {
            langWordScores = &found->second;
        }
    } else if (ngLen == 3) {
        auto ng = textNGrams_.randomTrigram();
        auto found = profileGroup_->trigramWeights.find(ng);
        if (found != profileGroup_->trigramWeights.end()) {
            langWordScores = &found->second;
        }
    }
    return langWordScores;
}

std::vector<double> DetectionRunner::runTrial() {
    std::vector<double> probs;
    double startingProb = 1.0 / static_cast<double>(profileGroup_->profiles.size());
    for (std::size_t i = 0; i < profileGroup_->profiles.size(); i++) {
        probs.push_back(startingProb);
    }
    for (std::size_t i = 0;; i++) {
        double weight = alpha_.get() / BASE_FREQ;
        auto langWordScores = getLanguageScoresForRandomNGramOrNull();
        if (langWordScores != nullptr) {
            for (std::size_t k = 0; k < langWordScores->size(); k++) {
                probs[k] *= (weight + langWordScores->at(k));
            }
        }

        if (i % 5 == 0) {
            double maxp = 0.0;
            double sump = 0.0;
            for (auto &elem : probs) {
                sump += elem;
            }
            for (double & prob : probs) {
                double p = prob / sump;
                if (maxp < p) {
                    maxp = p;
                }
                prob = p;
            }
            if (maxp > CONV_THRESHOLD || i >= ITERATION_LIMIT) {
                break;
            }
        }
    }
    return probs;
}

}  // namespace langdetectpp::detection
