//
// Created by Daniel on 06.04.2015.
//

#ifndef C_DEQUE_H
#define C_DEQUE_H

#include <vector>
#include <string>
#include <cstdlib>

template <class T>
class deque {
private:
    std::vector<T> data;
public:
    size_t size();
    void addFront(T const &item);
    T removeFront();
    void addRear(T const &item);
    T removeRear();
};

template <class T>
size_t deque<T>::size() {
    return data.size();
}

template <class T>
void deque<T>::addFront(T const &item) {
    data.insert(data.begin(), item);
}

template <class T>
void deque<T>::addRear(T const &item) {
    data.push_back(item);
}

template <class T>
T deque<T>::removeFront() {
    auto res = data.front();
    data.erase(data.begin());
    return res;
}

template <class T>
T deque<T>::removeRear() {
    auto res = data.back();
    data.pop_back();
    return res;
}

bool palchecker(std::string word);

#endif //C_DEQUE_H
