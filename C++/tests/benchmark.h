//
// Created by Daniel on 4/3/2015.
//

#ifndef C_BENCHMARK_H
#define C_BENCHMARK_H
#include <chrono>

void printBenchmark(const char *name, std::chrono::nanoseconds elapsed, int n);

#endif //C_BENCHMARK_H
