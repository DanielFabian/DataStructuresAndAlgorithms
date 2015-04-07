import unittest
from dequeue import Dequeue

__author__ = 'Daniel'


class TestMain(unittest.TestCase):
    def test_size(self):
        testee = Dequeue()
        self.assertEquals(0, testee.size())
        testee.add_front(1)
        self.assertEquals(1, testee.size())

    def test_add_front(self):
        testee = Dequeue()
        testee.add_front(1)
        testee.add_front(2)
        testee.add_front(3)
        self.assertEquals(1, testee.remove_rear())

    def test_add_rear(self):
        testee = Dequeue()
        testee.add_rear(1)
        testee.add_rear(2)
        testee.add_rear(3)
        self.assertEquals(3, testee.remove_rear())

    def test_remove_front(self):
        testee = Dequeue()
        testee.add_rear(1)
        testee.add_rear(2)
        testee.add_rear(3)
        self.assertEquals(1, testee.remove_front())
        self.assertEquals(2, testee.remove_front())
        self.assertEquals(3, testee.remove_front())
        self.assertEquals(0, testee.size())
