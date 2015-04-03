//
// Created by Daniel on 4/3/2015.
//

#include "trivial.h"

long long sum_of_n(int n)
{
    auto res = 0LL;
    for (auto i = 1LL; i <= n; i++) {
        res += i;
    }

    return res;
}


