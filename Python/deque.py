__author__ = 'Daniel'


class Deque:
    def __init__(self):
        self.data = []

    def add_front(self, item):
        self.data.insert(0, item)

    def add_rear(self, item):
        self.data.append(item)

    def remove_front(self):
        return self.data.pop(0)

    def remove_rear(self):
        return self.data.pop()

    def size(self):
        return len(self.data)


def palchecker(word):
    deque = Deque()
    for c in word:
        deque.add_rear(c)

    while deque.size() > 1:
        if deque.remove_front() != deque.remove_rear():
            return False

    return True