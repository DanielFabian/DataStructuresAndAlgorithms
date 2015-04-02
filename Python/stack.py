__author__ = 'Daniel'


class Stack():
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def is_empty(self):
        return self.items == []

    def size(self):
        return len(self.items)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]


def check_parentheses(inp):
    stack = Stack()
    for c in inp:
        if c == ')' or c == ']' or c == '}' or c == '>':
            if stack.is_empty() or stack.pop() != c:
                return False
        if c == '(':
            stack.push(')')
        if c == '[':
            stack.push(']')
        if c == '{':
            stack.push('}')
        if c == '<':
            stack.push('>')
    return stack.is_empty()


def to_base(num, base):
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    stack = Stack()
    while num > 0:
        stack.push(digits[num % base])
        num /= base

    res = ""
    while not stack.is_empty():
        res += stack.pop()

    return res


def to_binary(num):
    return to_base(num, 2)