package Stack
import (
    "fmt"
    "strings"
    "strconv"
)

type Stack struct {
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

func checkParentheses(str string) bool {
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

func toPostfix(str string) string {
    tokens := strings.Split(str, " ")
    prec := func(token string) int {
        switch token {
            case "+", "-":
            return 1
            case "*", "/":
            return 2
        }
        return 0
    }

    operators := new(Stack)

    var res []string

    for _, token := range tokens {
        switch token {
            case "(":
            operators.push("(")
            case ")":
            op := operators.pop()
            for op != "(" {
                res = append(res, op.(string))
                op = operators.pop()
            }
            case "+", "-", "*", "/":
            for !operators.isEmpty() && prec(token) <= prec(operators.peek().(string)) {
                res = append(res, operators.pop().(string))
            }
            operators.push(token)
            default:
            res = append(res, token)
        }
    }

    for !operators.isEmpty() {
        res = append(res, operators.pop().(string))
    }

    return strings.Join(res, " ")
}

type binOp func(int, int) int

func evalPostfix(str string) int {
    tokens := strings.Split(str, " ")
    evalStack := new(Stack)
    eval := func(f binOp) {
        right := evalStack.pop()
        left := evalStack.pop()
        evalStack.push(f(left.(int), right.(int)))
    }

    for _, token := range tokens {
        switch token {
            case "+":
            eval(func(x int, y int) int {return x + y})
            case "-":
            eval(func(x int, y int) int {return x - y})
            case "*":
            eval(func(x int, y int) int {return x * y})
            case "/":
            eval(func(x int, y int) int {return x / y})
            default:
            num, _ := strconv.ParseInt(token, 0, 32)
            evalStack.push(int(num))
        }
    }
    return evalStack.pop().(int)
}