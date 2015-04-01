//
// Created by Daniel on 31.03.2015.
//
#include "stack.h"
#include <boost/lexical_cast.hpp>
bool checkParentheses(std::string str) {
    auto parentheses = stack<char>();
    for (auto c : str) {
        if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (parentheses.isEmpty() || parentheses.pop() != c)
                return false;
        }
        if (c == '(') parentheses.push(')');
        if (c == '[') parentheses.push(']');
        if (c == '{') parentheses.push('}');
        if (c == '<') parentheses.push('>');
    }
    return parentheses.isEmpty();
}

std::string toBinary(int num) {
    auto digits = stack<int>();
    while (num > 0) {
        digits.push(num % 2);
        num /= 2;
    }

    auto res = std::string();

    while (!digits.isEmpty())
    {
        res += boost::lexical_cast<std::string>(digits.pop());
    }

    return res;
}
