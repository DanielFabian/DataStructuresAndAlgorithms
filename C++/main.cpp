#include <iostream>
#include <chrono>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

long long sum_of_n(int n);
void benchmark_sum_of_n();

int main() {
    cout << "Hello, World!" << endl;
    cout << sum_of_n(10) << endl;

    benchmark_sum_of_n();
    return 0;
}

long long sum_of_n(int n)
{
    auto res = 0LL;
    for (auto i = 1LL; i <= n; i++) {
        res += i;
    }

    return res;
}


void printBenchmark(const char *name, nanoseconds elapsed, int n)
{
    // doesn't work. Can't force C++ to NOT delete the function call...
    auto averageTime = (double) elapsed.count() / (double) n;
    if (averageTime < 1000.0)
    {
        printf("%s, iterations %d, %0.3f ns/op", name, n, averageTime);
    }
    else
    {
        printf("%s, iterations %d, %d ns/op", name, n, (int) averageTime);
    }
}

void benchmark_sum_of_n() {
    // doesn't work. can't force C++ to NOT delete the function call.
    auto n = 100000;
    auto start = high_resolution_clock::now();
    for (auto i = 1; i < n; i++) {
        sum_of_n(10000);
    }
    auto stop = high_resolution_clock::now();
    printBenchmark("sum_of_n", duration_cast<nanoseconds>(stop - start), n);
}