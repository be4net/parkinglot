// Copyright [2021] <Stanislav Volkov>

#include <iostream>
#include <vector>

#include "include/ScanLine.hpp"

static const u_int32_t number_of_items = 3000;
static const u_int32_t number_in_range = 24 *60 *60;

int main() {
    std::cout << "Parking lot, Version 0" << std::endl;
    std::vector <timerange_t> parkingLot;
    u_int32_t expected = 0;
    u_int32_t maxSecond = 0;
    u_int32_t minFirst = 0;

    // Fill the Vector with random values
    std::cout << "Genearating the vector with " << number_of_items << " pairs..." << std::endl;
    for (auto i = 0ul; i < number_of_items; ++i) {
        timerange_t range = {0, 0};
        while (range.first >= range.second) {
            range.first = (random() % number_in_range) + 1;
            range.second = (random() % number_in_range) + 1;
        }
        if (minFirst == 0 || minFirst > range.first) minFirst=range.first;
        if (maxSecond ==0 || maxSecond < range.second) maxSecond = range.second;
        parkingLot.push_back(range);
    }
    std::cout << "done." << std::endl;
    std::cout << "Calculating the expected value for test from unsorted vector..." << std::endl;
    // Calculate ther true value , what we are waiting for...
    // Too huge and long, but true, anougth for test only...
    for (auto i = minFirst; i <= maxSecond; ++i) {
        u_int32_t tmp = 0;
        for (auto x = 0ul; x < parkingLot.size(); ++x) {
            if (parkingLot.at(x).first <= i && parkingLot.at(x).second > i) {  // hint
                ++tmp;
            }
        }
        if (tmp > expected) expected = tmp;
    }
    std::cout << "Test result (expected value:" << expected << ") <> (actual value: "
              << getInterceptionCount(parkingLot) << ")." << std::endl;
    return 0;
}
