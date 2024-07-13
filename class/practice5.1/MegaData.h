#pragma once

#include <vector>

class MegaData {
public:
    std::vector<float> smallArray;
    std::vector<double> bigArray;

    MegaData();
    void reset();
};

