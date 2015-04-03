//
// Created by Daniel on 31.03.2015.
//
#include "stack.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <sstream>
using namespace boost::algorithm;

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

std::string toPostfix(std::string str) {
    std::vector<std::string> tokens;
    split(tokens, str, boost::is_space(), token_compress_on);
    auto prec = [] (auto str) {
        if(str == "+" || str == "-")
            return 1;
        if(str == "*" || str == "/")
            return 2;
        return 0;
    };

    auto operators = stack<std::string>();

    std::stringstream res;

    for (auto token : tokens) {
        if(token == "(")
            operators.push(token);
        else if (token == ")") {
            auto op = operators.pop();
            while (op != "(") {
                res << op << " ";
                op = operators.pop();
            };
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!operators.isEmpty() && prec(token) <= prec(operators.peek()))
                res << operators.pop() << " ";
            operators.push(token);
        }
        else
            res << token << " ";
    }

    while (!operators.isEmpty())
        res << operators.pop() << " ";

    return res.str().erase(res.str().length() - 1);
}

int evalPostfix(std::string str) {
    std::vector<std::string> tokens;
    split(tokens, str, boost::is_space(), token_compress_on);
    auto evalStack = stack<int>();
    auto eval = [&](auto binOp) {
        auto right = evalStack.pop();
        auto left = evalStack.pop();
        evalStack.push(binOp(left, right));
    };

    for(auto token : tokens)
    {
        if(token == "+") eval([](auto x, auto y) { return x + y; });
        else if(token == "-") eval([](auto x, auto y) { return x - y; });
        else if(token == "*") eval([](auto x, auto y) { return x * y; });
        else if(token == "/") eval([](auto x, auto y) { return x / y; });
        else evalStack.push(boost::lexical_cast<int>(token));
    }

    return evalStack.pop();
}
