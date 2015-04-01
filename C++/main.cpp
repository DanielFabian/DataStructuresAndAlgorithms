#include "main.h"
#include "stack.h"

#include <iostream>
#include <cstdio>
#include <tuple>
#include <assert.h>

using namespace std;
using namespace std::chrono;

int main() {

    testPop();
    testPush();
    testIsEmpty();
    testSize();

    testCheckParentheses();
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

void printBenchmark(const char *name, nanoseconds elapsed, int n) {
    // doesn't work. Can't force C++ to NOT delete the function call...
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

void testIsEmpty() {
    auto testee = stack<char>();
    assert(testee.isEmpty());

    testee.push(1);

    assert(!testee.isEmpty());
    cout << "testIsEmpty passed" << endl;
}

void testSize() {
    auto testee = stack<char>();

    assert(testee.size() == 0);

    testee.push(1);
    testee.push(2);

    assert(testee.size() == 2);
    cout << "testSize passed" << endl;
}

void testPush() {
    auto testee = stack<int>();
    testee.push(1);
    assert(testee.peek() == 1);
    testee.push(2);
    assert(testee.peek() == 2);
    testee.push(3);
    assert(testee.peek() == 3);
    assert(testee.size() == 3);
    cout << "testPush passed" << endl;
}

void testPop() {
    auto testee = stack<int>();
    testee.push(1);
    testee.push(2);
    testee.push(3);
    assert(testee.size() == 3);
    assert(testee.pop() == 3);
    assert(testee.size() == 2);
    cout << "testPop passed" << endl;
}

void testCheckParentheses() {
    auto tests = vector<tuple<bool, string>>();
    tests.push_back(make_tuple(true, "() [] () ([]()[])"));
    tests.push_back(make_tuple(true, "(()()()())"));
    tests.push_back(make_tuple(true, "(()((())()))"));
    tests.push_back(make_tuple(true, R"(#pragma once
#include <vector>
#include <cstdlib>

    template <class T>
    class stack {
    private:
        std::vector<T> data;
    public:
        void push(const T& item);
        T pop();
        T peek();
        bool isEmpty();
        size_t size();
    };)"));
    tests.push_back(make_tuple(false, "( (] ([)]"));
    tests.push_back(make_tuple(false, "((((((())"));
    tests.push_back(make_tuple(false, "()))"));
    tests.push_back(make_tuple(false, "(()()(()"));

    for (auto test : tests){
        assert(checkParentheses(get<1>(test)) == get<0>(test));
    }

    cout << "testCheckParentheses passed";
}