import random

__author__ = "Daniel"


class Queue:
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


def hot_potato(names, num):
    queue = Queue()
    for name in names:
        queue.enqueue(name)

    while queue.size() > 1:
        for _ in range(num):
            queue.enqueue(queue.dequeue())
        queue.dequeue()
    return queue.dequeue()


class Task:
    def __init__(self, time):
        self.timestamp = time
        self.pages = random.randrange(1, 21)

    def get_stamp(self):
        return self.timestamp

    def get_pages(self):
        return self.pages

    def wait_time(self, current_time):
        return current_time - self.timestamp


class Printer:
    def __init__(self, ppm):
        self.page_rate = ppm
        self.current_task = None
        self.time_remaining = 0

    def tick(self):
        if self.current_task is not None:
            self.time_remaining -= 1
            if self.time_remaining <= 0:
                self.current_task = None

    def get_busy(self):
        return self.current_task is not None

    def start_next(self, task):
        self.current_task = task
        self.time_remaining = task.get_pages() * 60 / self.page_rate


def print_queue(num_seconds, pages_per_minute):
    lab_printer = Printer(pages_per_minute)
    printer_queue = Queue()
    waiting_times = []

    def new_print_task():
        return random.randrange(1, 181) == 180

    for currentSecond in range(num_seconds):
        if new_print_task():
            printer_queue.enqueue(Task(currentSecond))

        if not lab_printer.get_busy() and not printer_queue.is_empty():
            next_task = printer_queue.dequeue()
            waiting_times.append(next_task.wait_time(currentSecond))
            lab_printer.start_next(next_task)

        lab_printer.tick()

    average_times = sum(waiting_times) / len(waiting_times)
    print("average wait: %6.2f seconds %3d tasks remaining." % (average_times, printer_queue.size()))