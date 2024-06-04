#ifndef MEGADATA_H
#define MEGADATA_H

#include <vector>
#include <memory>

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

public:
    explicit MegaDataPool(size_t size);
    MegaData* acquire();
    void release(MegaData* obj);
    size_t size() const;
    size_t usedSize() const;
};

#endif // MEGADATA_H

