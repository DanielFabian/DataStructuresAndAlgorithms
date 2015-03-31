import unittest
from stack import Stack

__author__ = 'Daniel'


class TestMain(unittest.TestCase):
    def test_push(self):
        stack = Stack()
        stack.push(1)
        stack.push("two")
        stack.push(3.0)
        self.assertEquals(stack.items, [1, "two", 3.0])

    def test_peek(self):
        stack = Stack()
        stack.push(1)
        stack.push("two")
        self.assertEquals(stack.items, [1, "two"])

        self.assertEquals(stack.peek(), "two")

        self.assertEquals(stack.items, [1, "two"])

    def test_pop(self):
        stack = Stack()
        stack.push(1)
        stack.push("two")
        self.assertEquals(stack.items, [1, "two"])

        self.assertEquals(stack.pop(), "two")

        self.assertEquals(stack.items, [1])

    def test_is_empty(self):
        stack = Stack()
        self.assertEquals(stack.is_empty(), True)

        stack.push(1)

        self.assertEquals(stack.is_empty(), False)

    def test_size(self):
        stack = Stack()

        stack.push(1)
        stack.push("two")

        self.assertEquals(stack.size(), 2)