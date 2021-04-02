#pragma once

#include "detection/detection_runner.h"
#include "ngrams/ngram_extractor.h"
#include "profiles/profile_group.h"
#include <langdetectpp/language.h>
#include <memory>
#include <utility>

namespace langdetectpp::detection
{

class DetectorImpl
{
  protected:
    std::shared_ptr<profiles::ProfileGroup> profileGroup_;

  public:
    explicit DetectorImpl(std::shared_ptr<profiles::ProfileGroup> profileGroup)
        : profileGroup_(std::move(profileGroup)) {
    }

    Language detect(const std::string &text) {
        ngrams::NGramExtractor extractor(text);
        auto extracted = extractor.extract();

        if (extracted.empty())
            return Language::UNKNOWN;

        DetectionRunner runner(profileGroup_, extracted);
        return runner.detect();
    }
};

}  // namespace langdetectpp::detection
