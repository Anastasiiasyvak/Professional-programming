#include "MegaDataPool.h"

MegaDataPool::MegaDataPool(size_t size) {
    pool.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        pool.push_back(std::make_unique<MegaData>());
        available.push_back(pool.back().get());
    }
}

[[nodiscard]] MegaData* MegaDataPool::acquire() {
    if (available.empty()) {
        return nullptr; 
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

