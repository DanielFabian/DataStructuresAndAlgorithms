//
// Created by Daniel on 4/3/2015.
//

#include <gtest/gtest.h>
#include <chrono>
#include "../trivial.h"
#include "benchmark.h"

TEST(Trivial, sum_of_n) {
    ASSERT_EQ(55, sum_of_n(10));
}

TEST(Trivial, benchmark_sum_of_n) {
    auto n = 10000;
    auto start = std::chrono::system_clock::now();
    for (auto i = 1; i < n; i++) {
        sum_of_n(10000);
    }
    auto stop = std::chrono::system_clock::now();
    printBenchmark("sum_of_n", std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start), n);
}
