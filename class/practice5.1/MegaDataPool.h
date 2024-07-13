#pragma once

#include <vector>
#include <memory>
#include "MegaData.h"

class MegaDataPool {
private:
    std::vector<std::unique_ptr<MegaData>> pool;
    std::vector<MegaData*> available;

public:
    explicit MegaDataPool(size_t size);
    [[nodiscard]] MegaData* acquire();
    void release(MegaData* obj);
    size_t size() const;
    size_t usedSize() const;
};

