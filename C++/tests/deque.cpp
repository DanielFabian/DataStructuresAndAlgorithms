//
// Created by Daniel on 06.04.2015.
//

#include "gtest/gtest.h"
#include "../deque.h"

TEST(Deque, size) {
    auto testee = deque<int>();
    ASSERT_EQ(0u, testee.size());
    testee.addFront(1);
    ASSERT_EQ(1u, testee.size());
}


TEST(Deque, addFront) {
    auto testee = deque<int>();
    testee.addFront(1);
    testee.addFront(2);
    testee.addFront(3);
    ASSERT_EQ(1, testee.removeRear());
}


TEST(Deque, addRear) {
    auto testee = deque<int>();
    testee.addRear(1);
    testee.addRear(2);
    testee.addRear(3);

    ASSERT_EQ(3, testee.removeRear());
}


TEST(Deque, removeFront) {
    auto testee = deque<int>();
    testee.addRear(1);
    testee.addRear(2);
    testee.addRear(3);

    ASSERT_EQ(1, testee.removeFront());
    ASSERT_EQ(2, testee.removeFront());
    ASSERT_EQ(3, testee.removeFront());
    ASSERT_EQ(0u, testee.size());
}

TEST(DequeReplatedAlgorithms, palchecker) {
    ASSERT_FALSE(palchecker("lsdkjfskf"));
    ASSERT_TRUE(palchecker("radar"));
}
