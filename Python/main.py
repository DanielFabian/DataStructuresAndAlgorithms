import time

__author__ = 'Daniel'

print("Hello World")


def sum_of_n(n):
    result = 0
    for i in range(1, n + 1):
        result += i

    return result

print(sum_of_n(10))


for i in range(5):
    start = time.time()
    res = sum_of_n(1000000)
    end = time.time()
    print("sum_of_n 10^6 = %d, took %9.7f seconds" % (res, (end - start)))