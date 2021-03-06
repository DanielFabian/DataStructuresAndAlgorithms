//
// Created by Daniel on 31.03.2015.
//

#ifndef C_STACK_H
#define C_STACK_H
#include <vector>
#include <cstdlib>
#include <string>

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
};


template <class T>
void stack<T>::push(T const &item) {
    data.push_back(item);
}

template <class T>
T stack<T>::pop() {
	auto res = data.back();
	data.pop_back();
	return res;
}

template <class T>
T stack<T>::peek() {
    return data.back();
}

template <class T>
size_t stack<T>::size() {
    return data.size();
}

template <class T>
bool stack<T>::isEmpty() {
    return data.empty();
}

bool checkParentheses(std::string str);

std::string toBinary(int num);

std::string toBase(int num, int base);

std::string toPostfix(std::string str);

int evalPostfix(std::string str);

#endif //C_STACK_H