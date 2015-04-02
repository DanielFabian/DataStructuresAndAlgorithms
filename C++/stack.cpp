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
    return toBase(num, 2);
}

std::string toBase(int num, int base) {
    auto digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    auto digitsInBase = stack<char>();
    while (num > 0) {
        digitsInBase.push(digits[num % base]);
        num /= base;
    }

    auto res = std::string();

    while (!digitsInBase.isEmpty())
    {
        res += digitsInBase.pop();
    }

    return res;
}
