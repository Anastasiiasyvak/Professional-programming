#include <cassert>
#include <iostream>
#include "MegaData.h"

void testMegaDataInitialization() {
    MegaData data;
    for (const auto& val : data.smallArray) {
        assert(val == 42.0f);
    }
    for (const auto& val : data.bigArray) {
        assert(val == 42.0);
    }
    std::cout << "testMegaDataInitialization passed." << std::endl;
}

void testMegaDataReset() {
    MegaData data;
    data.smallArray[0] = 0.0f;
    data.bigArray[0] = 0.0;
    data.reset();
    assert(data.smallArray[0] == 42.0f);
    assert(data.bigArray[0] == 42.0);
    std::cout << "testMegaDataReset passed." << std::endl;
}

void testMegaDataPoolAcquireRelease() {
    MegaDataPool pool(10);
    assert(pool.size() == 10);
    assert(pool.usedSize() == 0);

    MegaData* data1 = pool.acquire();
    assert(data1 != nullptr);
    assert(pool.usedSize() == 1);

    pool.release(data1);
    assert(pool.usedSize() == 0);
    std::cout << "testMegaDataPoolAcquireRelease passed." << std::endl;
}

void testMegaDataPoolExhaustion() {
    MegaDataPool pool(2);
    MegaData* data1 = pool.acquire();
    MegaData* data2 = pool.acquire();
    MegaData* data3 = pool.acquire();
    assert(data1 != nullptr);
    assert(data2 != nullptr);
    assert(data3 == nullptr); 
    std::cout << "testMegaDataPoolExhaustion passed." << std::endl;
}

int main() {
    testMegaDataInitialization();
    testMegaDataReset();
    testMegaDataPoolAcquireRelease();
    testMegaDataPoolExhaustion();
    std::cout << "All tests passed." << std::endl;
    return 0;
}

