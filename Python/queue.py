__author__ = "Daniel"


class Queue():
    """ Bad implementation of a queue with O(n) enqueue """
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.insert(0, item)

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

    def dequeue(self):
        return self.items.pop()
