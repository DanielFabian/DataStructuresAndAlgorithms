//
// Created by Daniel on 31.03.2015.
//
#include "stack.h"
bool checkParentheses(std::string str) {
    auto myStack = stack<char>();
    for (auto c : str) {
        if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (myStack.isEmpty() || myStack.pop() != c)
                return false;
        }
        if (c == '(') myStack.push(')');
        if (c == '[') myStack.push(']');
        if (c == '{') myStack.push('}');
        if (c == '<') myStack.push('>');
    }
    return myStack.isEmpty();
}
