package main
import (
    "fmt"
)

type Stack struct  {
    data []interface{}
}

func (s *Stack) size() int {
    return len(s.data)
}

func (s *Stack) push(item interface{}) {
    s.data = append(s.data, item)
}

func (s *Stack) peek() interface{} {
    return s.data[len(s.data) - 1]
}

func (s *Stack) pop() interface{} {
    idx := len(s.data) - 1
    res := s.data[idx]
    s.data = s.data[0:idx]
    return res
}

func (s *Stack) isEmpty() bool {
    return len(s.data) == 0
}

func checkParentheses (str string) bool {
    stack := new(Stack);
    for _, c := range str {
        if c == ')' || c == ']' || c == '}' || c == '>' {
            if stack.isEmpty() || stack.pop() != c {
                return false;
            }
        }
        if c == '(' { stack.push(')') }
        if c == '[' { stack.push(']') }
        if c == '{' { stack.push('}') }
        if c == '<' { stack.push('>') }
    }

    return stack.isEmpty()
}

func toBase(num int, base int) string {
    digits := "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    stack := new(Stack)
    for num > 0 {
        stack.push(digits[num % base])
        num /= base
    }

    res := ""
    for !stack.isEmpty() {
        res += fmt.Sprintf("%c", stack.pop())
    }

    return res
}

func toBinary(num int) string {
    return toBase(num, 2);
}