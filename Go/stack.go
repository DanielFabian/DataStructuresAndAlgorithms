package main

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