import unittest
import time
from main import sum_of_n


def print_benchmark(name, elapsed, n):
    average_time = elapsed * 1000000000.0 / n
    if average_time < 1000:
        print(format("%s, iterations %d, %0.3f ns/op" % (name, n, average_time)))
    else:
        print(format("%s, iterations %d, %d ns/op" % (name, n, average_time)))


class TestMain(unittest.TestCase):
    def test_sum_of_n(self):
        self.assertEquals(50005000, sum_of_n(10000))

    def test_benchmark_sum_of_n(self):
        n = 100
        start = time.time()
        for i in range(n):
            sum_of_n(10000)
        stop = time.time()

        print_benchmark("sum_of_n", stop - start, n)