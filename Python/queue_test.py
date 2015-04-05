from queue import Queue, hot_potato, print_queue
import unittest

__author__ = 'Daniel'


class TestMain(unittest.TestCase):
    def test_push(self):
        stack = Queue()
        stack.enqueue(1)
        stack.enqueue("two")
        stack.enqueue(3.0)
        self.assertEquals([3.0, "two", 1], stack.items)

    def test_pop(self):
        stack = Queue()
        stack.enqueue(1)
        stack.enqueue("two")
        self.assertEquals(["two", 1], stack.items)

        self.assertEquals(1, stack.dequeue())

        self.assertEquals(["two"], stack.items)

    def test_is_empty(self):
        stack = Queue()
        self.assertEquals(True, stack.is_empty())

        stack.enqueue(1)

        self.assertEquals(False, stack.is_empty())

    def test_size(self):
        stack = Queue()

        self.assertEquals(0, stack.size())

        stack.enqueue(1)
        stack.enqueue("two")

        self.assertEquals(2, stack.size())

    def test_hot_potato(self):
        self.assertEquals("Susan", hot_potato(["Bill", "David", "Susan", "Jane", "Kent", "Brad"], 7))

    def test_print_queue(self):
        for i in range(10):
            print_queue(3600, 5)