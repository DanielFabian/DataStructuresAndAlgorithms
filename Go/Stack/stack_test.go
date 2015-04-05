package Stack
import "testing"

func Test_size(t *testing.T) {
    testee := new(Stack)
    if testee.size() != 0 {
        t.Errorf("size of empty stack should be 0")
    }
    testee.push(1)
    if testee.size() != 1 {
        t.Errorf("size after one push, should be 1")
    }
}

func Test_push(t *testing.T) {
    testee := new(Stack)
    testee.push(1)

    if testee.peek() != 1 {
        t.Errorf("the top item should be read properly")
    }
}

func Test_pop(t *testing.T) {
    testee := new(Stack)
    testee.push(1)
    testee.push(2)
    res := testee.pop()

    if res != 2 {
        t.Errorf("the popped item should be the same as the one put in")
    }

    if testee.size() != 1 {
        t.Errorf("after removing, the stack should have length 1")
    }
}

func Test_isEmpty(t *testing.T) {
    testee := new(Stack)
    if testee.isEmpty() != true {
        t.Errorf("An initial stack is empty")
    }

    testee.push(1)

    if testee.isEmpty() {
        t.Errorf("After pushing the stack is no longer empty")
    }
}

func Test_checkParentheses(t *testing.T) {
    tests := []struct { expected bool; in string }{
        {true, "() [] () ([]()[])"},
        {true, "(()()()())"},
        {true, "(()((())()))"},
        {true, `#pragma once
#include <cstdlib>
#include <vector>

template <class T>
class stack {
    private:
    std::vector<T> data;
public:
    void push(const T& item);
    T pop();
    T peek();
    bool isEmpty();
    size_t size();
};`},
        {false, "( (] ([)]"},
        {false, "((((((())"},
        {false, "()))"},
        {false, "(()()(()"},
    }

    for _, test := range tests {
        if checkParentheses(test.in) != test.expected {
            t.Errorf("wrong parentheses check on input: %s", test.in)
        }
    }
}

func Test_toBinary(t *testing.T) {
    actual := toBinary(233)
    if actual != "11101001" {
        t.Errorf("wrong binary transform: %s, expected 11101001", actual)
    }
}

func Test_toBase(t *testing.T) {
    tests := [] struct { num, base int; exp string }{
        {233, 2, "11101001" },
        {233, 8, "351" },
        {233, 16, "E9" },
    }

    for _, test := range tests {
        actual := toBase(test.num, test.base)
        if actual != test.exp {
            t.Errorf("wrong base transform: toBase(%d, %d) = %s, expected %s", test.num, test.base, actual, test.exp)
        }
    }
}

func Test_toPostfix(t *testing.T) {
    tests := [] struct { inp, exp string }{
        { "( A + B ) * ( C + D )", "A B + C D + *" },
        { "( A + B ) * C", "A B + C *" },
        { "A + B * C", "A B C * +" },
    }

    for _, test := range tests {
        actual := toPostfix(test.inp)
        if actual != test.exp {
            t.Errorf("wrong to postfix transform: toPostfix(\"%s\") = \"%s\", expected \"%s\"", test.inp, actual, test.exp)
        }
    }
}

func Test_evalPostfix(t *testing.T) {
    tests := [] struct { inp string; exp int }{
        { "7 8 + 3 2 + /", 3 },
        { "17 10 + 3 * 9 /", 9 },
        { "5 1 2 + 4 * + 3 -", 14 },
        { "3 4 + 5 *", 35 },
        { "1 2 + 3 4 + *", 21 },
    }

    for _, test := range tests {
        actual := evalPostfix(test.inp)
        if actual != test.exp {
            t.Errorf("wrong postfix evaluation: evalPostfix(\"%s\") = %d, expected %d", test.inp, actual, test.exp)
        }
    }
}