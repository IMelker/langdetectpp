#pragma once
#include <array>
#include <functional>
#include <tuple>

namespace langdetectpp::util
{

template<typename T, std::size_t n>
class CircleArray
{
  protected:
    std::array<T, n> elements_;
    std::size_t count_{0};

  public:
    static const std::size_t max_size = n;

    void push(T t) {
        if (count_ < n) {
            elements_[count_] = t;
            count_++;
        } else {
            for (std::size_t i = 1; i < n; i++) {
                elements_[i - 1] = elements_[i];
            }
            elements_[n - 1] = t;
        }
    }

    typename std::array<T, n>::iterator begin() {
        return elements_.begin();
    }

    typename std::array<T, n>::iterator end() {
        return elements_.end();
    }

    T getOne() {
        return elements_[0];
    }

    std::tuple<T, T> getTwo() {
        return std::make_tuple(
            elements_[0],
            elements_[1]);
    }

    std::tuple<T, T, T> getThree() {
        return std::make_tuple(
            elements_[0],
            elements_[1],
            elements_[2]);
    }
};

}  // namespace langdetectpp::util
