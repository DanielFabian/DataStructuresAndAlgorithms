__author__ = 'Daniel'


class Stack:
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
        num //= base

    res = ""
    while not stack.is_empty():
        res += stack.pop()

    return res


def to_binary(num):
    return to_base(num, 2)


def to_postfix(string):
    tokens = string.split()
    prec = {"+": 1, "-": 1, "*": 2, "/": 2, "(": 0, ")": 0}
    operators = Stack()

    res = []
    for token in tokens:
        if token == "(":
            operators.push("(")
        elif token == ")":
            op = operators.pop()
            while op != "(":
                res.append(op)
                op = operators.pop()
        elif token in "+-*/":
            while not operators.is_empty() and prec[token] <= prec[operators.peek()]:
                res.append(operators.pop())
            operators.push(token)
        else:
            res.append(token)

    while not operators.is_empty():
        res.append(operators.pop())

    return " ".join(res)


def eval_postfix(string):
    tokens = string.split()

    def eval_op(f):
        right = eval_stack.pop()
        left = eval_stack.pop()
        eval_stack.push(f(left, right))

    eval_stack = Stack()
    from operator import add, floordiv, mul, sub

    for token in tokens:
        if token == "+":
            eval_op(add)
        elif token == "-":
            eval_op(sub)
        elif token == "*":
            eval_op(mul)
        elif token == "/":
            eval_op(floordiv)
        else:
            eval_stack.push(int(token))

    return eval_stack.pop()
