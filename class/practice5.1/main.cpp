#include <cassert>
#include <print>
#include "MegaData.h"
#include "MegaDataPool.h"

void testMegaDataInitialization() {
    MegaData data;

    for (const auto& val : data.smallArray) {
        assert(val == 42.0f);
    }
    for (const auto& val : data.bigArray) {
        assert(val == 42.0);
    }

    std::println("testMegaDataInitialization passed.");
}

void testMegaDataReset() {
    MegaData data;
    data.smallArray[0] = 0.0f;
    data.bigArray[0] = 0.0;

    data.reset();

    assert(data.smallArray[0] == 42.0f);
    assert(data.bigArray[0] == 42.0);

    std::println("testMegaDataReset passed.");
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

    std::println("testMegaDataPoolAcquireRelease passed.");
}

void testMegaDataPoolExhaustion() {
    MegaDataPool pool(2);

    MegaData* data1 = pool.acquire();
    MegaData* data2 = pool.acquire();
    MegaData* data3 = pool.acquire();

    assert(data1 != nullptr);
    assert(data2 != nullptr);
    assert(data3 == nullptr); 

    std::println("testMegaDataPoolExhaustion passed.");
}

int main() {
    testMegaDataInitialization();
    testMegaDataReset();
    testMegaDataPoolAcquireRelease();
    testMegaDataPoolExhaustion();
    std::println("All tests passed.");
    return 0;
}

