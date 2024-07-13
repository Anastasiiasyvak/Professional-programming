#include "MegaData.h"

constexpr size_t SMALL_ARRAY_SIZE = 1024;
constexpr size_t BIG_ARRAY_SIZE = 1024 * 1024;

MegaData::MegaData()
    : smallArray(SMALL_ARRAY_SIZE, 42.0f), bigArray(BIG_ARRAY_SIZE, 42.0) {
}

void MegaData::reset() {
    std::fill(smallArray.begin(), smallArray.end(), 42.0f);
    std::fill(bigArray.begin(), bigArray.end(), 42.0);
}

