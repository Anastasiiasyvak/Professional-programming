#ifndef MEGADATA_H
#define MEGADATA_H

#include <vector>
#include <memory>
#include <mutex>

class MegaData {
public:
    std::vector<float> smallArray;
    std::vector<double> bigArray;

    MegaData();
    void reset();
};

class MegaDataPool {
private:
    std::vector<std::unique_ptr<MegaData>> pool;
    std::vector<MegaData*> available;
    mutable std::mutex poolMutex;

    MegaDataPool(size_t size);

    MegaDataPool(const MegaDataPool&) = delete;
    MegaDataPool& operator=(const MegaDataPool&) = delete;

public:
    static MegaDataPool& getInstance(size_t size);

    MegaData* acquire();
    void release(MegaData* obj);
    size_t size() const;
    size_t usedSize() const;
};


MegaData* acquireObjectFromPool();
void releaseObjectToPool(MegaData* obj);
size_t getPoolUsedSize();

#endif
