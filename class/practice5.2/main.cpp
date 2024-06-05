#include <cassert>
#include <iostream>
#include <thread>
#include <vector>
#include "MegaData.h"

void testSingletonAccess() {
    MegaData* data1 = acquireObjectFromPool();
    assert(data1 != nullptr);
    releaseObjectToPool(data1);
    std::cout << "testSingletonAccess passed." << std::endl;
}

void testThreadSafeAccess() {
    MegaDataPool& pool = MegaDataPool::getInstance(10);

    auto threadFunc = [&pool]() {
        MegaData* data = pool.acquire();
        assert(data != nullptr);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        pool.release(data);
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(threadFunc));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    assert(pool.usedSize() == 0);
    std::cout << "testThreadSafeAccess passed." << std::endl;
}

int main() {
    testSingletonAccess();
    testThreadSafeAccess();
    std::cout << "All tests passed." << std::endl;
    return 0;
}
