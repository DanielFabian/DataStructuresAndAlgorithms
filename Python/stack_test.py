import unittest
from stack import *

__author__ = 'Daniel'


class TestMain(unittest.TestCase):
    def test_push(self):
        stack = Stack()
        stack.push(1)
        stack.push("two")
        stack.push(3.0)
        self.assertEquals([1, "two", 3.0], stack.items)

    def test_peek(self):
        stack = Stack()
        stack.push(1)
        stack.push("two")
        self.assertEquals([1, "two"], stack.items)

        self.assertEquals("two", stack.peek())

        self.assertEquals([1, "two"], stack.items)

    def test_pop(self):
        stack = Stack()
        stack.push(1)
        stack.push("two")
        self.assertEquals([1, "two"], stack.items)

        self.assertEquals("two", stack.pop())

        self.assertEquals([1], stack.items)

    def test_is_empty(self):
        stack = Stack()
        self.assertEquals(True, stack.is_empty())

        stack.push(1)

        self.assertEquals(False, stack.is_empty())

    def test_size(self):
        stack = Stack()

        self.assertEquals(0, stack.size())

        stack.push(1)
        stack.push("two")

        self.assertEquals(2, stack.size())

    def test_parentheses(self):
        tests = [
            (True, "() [] () ([]()[])"),
            (True, "(()()()())"),
            (True, "(()((())()))"),
            (True, """#pragma once
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
};"""),
            (False, "( (] ([)]"),
            (False, "((((((())"),
            (False, "()))"),
            (False, "(()()(()"),
        ]

        for (exp, inp) in tests:
            self.assertEquals(check_parentheses(inp), exp, inp)

    def test_to_binary(self):
        self.assertEquals("11101001", to_binary(233))

    def test_to_base(self):
        self.assertEquals("11101001", to_base(233, 2))
        self.assertEquals("351", to_base(233, 8))
        self.assertEquals("E9", to_base(233, 16))