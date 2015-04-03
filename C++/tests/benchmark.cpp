//
// Created by Daniel on 4/3/2015.
//

#include <stdio.h>
#include "benchmark.h"

void printBenchmark(const char *name, std::chrono::nanoseconds elapsed, int n) {
    auto averageTime = (double) elapsed.count() / (double) n;
    if (averageTime < 1000.0)
    {
        printf("%s, iterations %d, %0.3f ns/op\n", name, n, averageTime);
    }
    else
    {
        printf("%s, iterations %d, %d ns/op\n", name, n, (int) averageTime);
    }
}