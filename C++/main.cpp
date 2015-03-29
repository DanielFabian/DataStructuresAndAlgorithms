#include <iostream>
#include <chrono>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

long long sum_of_n(int n);


int main() {
    cout << "Hello, World!" << endl;
    cout << sum_of_n(10) << endl;

    for (int i = 0; i < 5; i++) {
        auto start = high_resolution_clock::now();
        auto res = sum_of_n(1000000);
        auto stop = high_resolution_clock::now();
        printf("sum_of_n 10^6 = %qi, took %9.7f seconds\n", res, duration_cast<microseconds>(stop - start).count() / 1000000.0);
    }
    return 0;
}

long long sum_of_n(int n)
{
    auto res = 0LL;
    for (auto i = 1; i <= n; i++) {
        res += i;
    }

    return res;
}