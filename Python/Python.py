__author__ = 'Daniel'

print("Hello World")


def sum_of_n(n):
    result = 0
    for i in range(1, n + 1):
        result += i

    return result

print(sum_of_n(10))