#include "MegaData.h"
#include <algorithm>
#include <iostream>

constexpr size_t SMALL_ARRAY_SIZE = 1024;
constexpr size_t BIG_ARRAY_SIZE = 1024 * 1024;

MegaData::MegaData()
        : smallArray(SMALL_ARRAY_SIZE, 42.0f), bigArray(BIG_ARRAY_SIZE, 42.0) {}

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

MegaDataPool& MegaDataPool::getInstance(size_t size) {
static MegaDataPool instance(size);
return instance;
}

MegaData* MegaDataPool::acquire() {
    std::lock_guard<std::mutex> lock(poolMutex);
    if (available.empty()) {
        return nullptr;
    }
    MegaData* obj = available.back();
    available.pop_back();
    return obj;
}

void MegaDataPool::release(MegaData* obj) {
    std::lock_guard<std::mutex> lock(poolMutex);
    obj->reset();
    available.push_back(obj);
}

size_t MegaDataPool::size() const {
    return pool.size();
}

size_t MegaDataPool::usedSize() const {
    std::lock_guard<std::mutex> lock(poolMutex);
    return pool.size() - available.size();
}

MegaData* acquireObjectFromPool() {
    return MegaDataPool::getInstance(10).acquire();
}

void releaseObjectToPool(MegaData* obj) {
    MegaDataPool::getInstance(10).release(obj);
}

size_t getPoolUsedSize() {
    return MegaDataPool::getInstance(10).usedSize();
}
