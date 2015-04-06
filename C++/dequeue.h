//
// Created by Daniel on 06.04.2015.
//

#ifndef C_DEQUEUE_H
#define C_DEQUEUE_H

#include <vector>
#include <cstdlib>

template <class T>
class dequeue {
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
size_t dequeue<T>::size() {
    return data.size();
}

template <class T>
void dequeue<T>::addFront(T const &item) {
    data.insert(data.begin(), item);
}

template <class T>
void dequeue<T>::addRear(T const &item) {
    data.push_back(item);
}

template <class T>
T dequeue<T>::removeFront() {
    auto res = data.front();
    data.erase(data.begin());
    return res;
}

template <class T>
T dequeue<T>::removeRear() {
    auto res = data.back();
    data.pop_back();
    return res;
}

#endif //C_DEQUEUE_H
