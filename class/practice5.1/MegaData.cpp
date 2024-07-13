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

MegaDataPool::MegaDataPool(size_t size) {
    pool.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        pool.push_back(std::make_unique<MegaData>());
        available.push_back(pool.back().get());
    }
}

MegaData* MegaDataPool::acquire() {
    if (available.empty()) {
        return nullptr; // Pool is empty
    }
    MegaData* obj = available.back();
    available.pop_back();
    return obj;
}

void MegaDataPool::release(MegaData* obj) {
    obj->reset();
    available.push_back(obj);
}

size_t MegaDataPool::size() const {
    return pool.size();
}

size_t MegaDataPool::usedSize() const {
    return pool.size() - available.size();
}
