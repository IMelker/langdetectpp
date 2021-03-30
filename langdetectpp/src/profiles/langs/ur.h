#pragma once
#include <tuple>
#include <unordered_map>
#include "util/tuple_hash.h"

namespace langdetectpp::profiles::langs {

std::unordered_map<uint32_t, size_t> get_ur_one_grams();
std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_ur_bigrams();
std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_ur_trigrams();
std::tuple<size_t, size_t, size_t> get_ur_n_words();

} // langdetectpp::profiles::langs

