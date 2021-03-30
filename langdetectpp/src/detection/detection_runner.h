#pragma once
#include <memory>
#include <tuple>
#include <vector>
#include "ngrams/extracted_ngrams.h"
#include "profiles/profile_group.h"
#include "util/stats.h"

namespace langdetectpp::detection
{

class DetectionRunner
{
  public:
    DetectionRunner(std::shared_ptr<profiles::ProfileGroup>, ngrams::ExtractedNGrams &);

    Language detect();
  protected:
    std::vector<double> runTrial();
    Language getBestScore();
    std::vector<double> *getLanguageScoresForRandomNGramOrNull();

    std::shared_ptr<profiles::ProfileGroup> profileGroup_;
    ngrams::ExtractedNGrams &textNGrams_;
    std::vector<double> langScores_;
    util::UniformIntDist ngramLengthDist_{1, 3};
    util::Alpha alpha_{0.5, 0.05};
};

}  // namespace langdetectpp::detection
