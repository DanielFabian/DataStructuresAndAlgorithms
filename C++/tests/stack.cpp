//
// Created by Daniel on 4/3/2015.
//


#include "gtest/gtest.h"
#include "../stack.h"

using namespace std;

TEST(StackRelatedAlgorithms, evalPostfix) {
    ASSERT_EQ(3, evalPostfix("7 8 + 3 2 + /"));
    ASSERT_EQ(9, evalPostfix("17 10 + 3 * 9 /"));
    ASSERT_EQ(14, evalPostfix("5 1 2 + 4 * + 3 -"));
    ASSERT_EQ(35, evalPostfix("3 4 + 5 *"));
    ASSERT_EQ(21, evalPostfix("1 2 + 3 4 + *"));
}

TEST(StackRelatedAlgorithms, toPostfix) {
    ASSERT_EQ("A B + C D + *", toPostfix("( A + B ) * ( C + D )"));
    ASSERT_EQ("A B + C *", toPostfix("( A + B ) * C"));
    ASSERT_EQ("A B C * +", toPostfix("A + B * C"));
}

TEST(StackRelatedAlgorithms, toBase) {
    ASSERT_EQ("11101001", toBase(233, 2));
    ASSERT_EQ("351", toBase(233, 8));
    ASSERT_EQ("E9", toBase(233, 16));
}

TEST(StackRelatedAlgorithms, toBinary) {
    ASSERT_EQ("11101001", toBinary(233));
}

TEST(StackRelatedAlgorithms, checkParentheses) {
    ASSERT_TRUE(checkParentheses("() [] () ([]()[])"));
    ASSERT_TRUE(checkParentheses("(()()()())"));
    ASSERT_TRUE(checkParentheses("(()((())()))"));
    auto code =
R"(#pragma once
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
};)";

    ASSERT_TRUE(checkParentheses(code));
    ASSERT_FALSE(checkParentheses("( (] ([)]"));
    ASSERT_FALSE(checkParentheses("((((((())"));
    ASSERT_FALSE(checkParentheses("()))"));
    ASSERT_FALSE(checkParentheses("(()()(()"));
}

TEST(Stack, push) {
    auto testee = stack<int>();
    testee.push(1);
    ASSERT_EQ(1, testee.peek());
    testee.push(2);
    ASSERT_EQ(2, testee.peek());
    testee.push(3);
    ASSERT_EQ(3, testee.peek());
    ASSERT_EQ(3u, testee.size());
}

TEST(Stack, pop) {
    auto testee = stack<int>();
    testee.push(1);
    testee.push(2);
    testee.push(3);
    ASSERT_EQ(3u, testee.size());
    ASSERT_EQ(3, testee.pop());
    ASSERT_EQ(2u, testee.size());
}

TEST(Stack, size) {
    auto testee = stack<char>();

    ASSERT_EQ(0u, testee.size());

    testee.push(1);
    testee.push(2);

    ASSERT_EQ(2u, testee.size());
}

TEST(Stack, isEmpty)
{
    auto testee = stack<char>();
    ASSERT_TRUE(testee.isEmpty());

    testee.push(1);

    ASSERT_FALSE(testee.isEmpty());
}