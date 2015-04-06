//
// Created by Daniel on 06.04.2015.
//

#include "gtest/gtest.h"
#include "../dequeue.h"

TEST(Dequeue, size) {
    auto testee = dequeue<int>();
    ASSERT_EQ(0u, testee.size());
    testee.addFront(1);
    ASSERT_EQ(1u, testee.size());
}


TEST(Dequeue, addFront) {
    auto testee = dequeue<int>();
    testee.addFront(1);
    testee.addFront(2);
    testee.addFront(3);
    ASSERT_EQ(1, testee.removeRear());
}


TEST(Dequeue, addRear) {
    auto testee = dequeue<int>();
    testee.addRear(1);
    testee.addRear(2);
    testee.addRear(3);

    ASSERT_EQ(3, testee.removeRear());
}


TEST(Dequeue, removeFront) {
    auto testee = dequeue<int>();
    testee.addRear(1);
    testee.addRear(2);
    testee.addRear(3);

    ASSERT_EQ(1, testee.removeFront());
    ASSERT_EQ(2, testee.removeFront());
    ASSERT_EQ(3, testee.removeFront());
    ASSERT_EQ(0u, testee.size());
}