//
// Created by Daniel on 31.03.2015.
//

#pragma once

#include <chrono>

long long sum_of_n(int n);
void benchmark_sum_of_n();
void printBenchmark(const char *name, std::chrono::nanoseconds elapsed, int n);
void testCheckParentheses();
void testPush();
void testPop();
void testSize();
void testIsEmpty();
void testToBinary();
void testToBase();
void testToPostfix();
void testEvalPostfix();

