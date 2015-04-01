package main
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
    tests := []struct { expected bool; in string } {
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