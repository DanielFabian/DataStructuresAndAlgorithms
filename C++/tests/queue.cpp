//
// Created by Daniel on 4/5/2015.
//

#include <gtest/gtest.h>
#include "../queue.h"

TEST(Queue, enqueue) {
    auto testee = queue<int>();
    testee.enqueue(1);
    testee.enqueue(2);
    testee.enqueue(3);
    ASSERT_EQ(1, testee.dequeue());
    ASSERT_EQ(2u, testee.size());
}

TEST(Queue, dequeue) {
    auto testee = queue<int>();
    testee.enqueue(1);
    testee.enqueue(2);
    testee.enqueue(3);
    ASSERT_EQ(3u, testee.size());
    ASSERT_EQ(1, testee.dequeue());
    ASSERT_EQ(2u, testee.size());
    ASSERT_EQ(2, testee.dequeue());
    ASSERT_EQ(1u, testee.size());
    ASSERT_EQ(3, testee.dequeue());
    ASSERT_EQ(0u, testee.size());
}

TEST(Queue, size) {
    auto testee = queue<char>();

    ASSERT_EQ(0u, testee.size());

    testee.enqueue(1);
    testee.enqueue(2);

    ASSERT_EQ(2u, testee.size());
}

TEST(Queue, isEmpty) {
    auto testee = queue<char>();
    ASSERT_TRUE(testee.isEmpty());

    testee.enqueue(1);

    ASSERT_FALSE(testee.isEmpty());
}

TEST(QueueRelatedAlgorithms, hotPotato) {
    auto names = std::vector<std::string>({"Bill", "David", "Susan", "Jane", "Kent", "Brad"});
    ASSERT_EQ("Susan", hotPotato(names, 7));
}
