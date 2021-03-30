#pragma once
#include <memory>
#include "language.h"

namespace langdetectpp
{

namespace detection
{
class DetectorImpl;
}  // namespace detection

class Detector
{
  public:
    static std::shared_ptr<Detector> create();

    Language detect(const std::string &);
  protected:
    explicit Detector(std::unique_ptr<detection::DetectorImpl>);

    std::unique_ptr<detection::DetectorImpl> pImpl_;
};

}  // namespace langdetectpp
