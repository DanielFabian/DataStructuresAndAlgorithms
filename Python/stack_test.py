import unittest
from stack import *

__author__ = 'Daniel'


class TestMain(unittest.TestCase):
    def test_push(self):
        testee = Stack()
        testee.push(1)
        testee.push("two")
        testee.push(3.0)
        self.assertEquals([1, "two", 3.0], testee.items)

    def test_peek(self):
        testee = Stack()
        testee.push(1)
        testee.push("two")
        self.assertEquals([1, "two"], testee.items)

        self.assertEquals("two", testee.peek())

        self.assertEquals([1, "two"], testee.items)

    def test_pop(self):
        testee = Stack()
        testee.push(1)
        testee.push("two")
        self.assertEquals([1, "two"], testee.items)

        self.assertEquals("two", testee.pop())

        self.assertEquals([1], testee.items)

    def test_is_empty(self):
        stack = Stack()
        self.assertEquals(True, stack.is_empty())

        stack.push(1)

        self.assertEquals(False, stack.is_empty())

    def test_size(self):
        testee = Stack()

        self.assertEquals(0, testee.size())

        testee.push(1)
        testee.push("two")

        self.assertEquals(2, testee.size())

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

    def test_to_postfix(self):
        self.assertEquals("A B + C D + *", to_postfix("( A + B ) * ( C + D )"))
        self.assertEquals("A B + C *", to_postfix("( A + B ) * C"))
        self.assertEquals("A B C * +", to_postfix("A + B * C"))

    def test_eval_postfix(self):
        self.assertEquals(3, eval_postfix("7 8 + 3 2 + /"))
        self.assertEquals(9, eval_postfix("17 10 + 3 * 9 /"))
        self.assertEquals(14, eval_postfix("5 1 2 + 4 * + 3 -"))
        self.assertEquals(35, eval_postfix("3 4 + 5 *"))
        self.assertEquals(21, eval_postfix("1 2 + 3 4 + *"))

