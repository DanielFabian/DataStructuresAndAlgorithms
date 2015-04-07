from queue import Queue, hot_potato, print_queue
import unittest

__author__ = 'Daniel'


class TestMain(unittest.TestCase):
    def test_push(self):
        testee = Queue()
        testee.enqueue(1)
        testee.enqueue("two")
        testee.enqueue(3.0)
        self.assertEquals([3.0, "two", 1], testee.items)

    def test_pop(self):
        testee = Queue()
        testee.enqueue(1)
        testee.enqueue("two")
        self.assertEquals(["two", 1], testee.items)

        self.assertEquals(1, testee.dequeue())

        self.assertEquals(["two"], testee.items)

    def test_is_empty(self):
        testee = Queue()
        self.assertEquals(True, testee.is_empty())

        testee.enqueue(1)

        self.assertEquals(False, testee.is_empty())

    def test_size(self):
        testee = Queue()

        self.assertEquals(0, testee.size())

        testee.enqueue(1)
        testee.enqueue("two")

        self.assertEquals(2, testee.size())

    def test_hot_potato(self):
        self.assertEquals("Susan", hot_potato(["Bill", "David", "Susan", "Jane", "Kent", "Brad"], 7))

    def test_print_queue(self):
        for i in range(10):
            print_queue(3600, 5)