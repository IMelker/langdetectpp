#pragma once
#include <unordered_map>
#include <tuple>
#include "util/tuple_hash.h"

namespace langdetectpp::profiles::langs {

std::unordered_map<uint32_t, size_t> get_zh_cn_one_grams();
std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_zh_cn_bigrams();
std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_zh_cn_trigrams();
std::tuple<size_t, size_t, size_t> get_zh_cn_n_words();

} // langdetectpp::profiles::langs

