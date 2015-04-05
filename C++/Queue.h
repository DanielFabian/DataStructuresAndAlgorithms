//
// Created by Daniel on 4/5/2015.
//

#ifndef C_QUEUE_H
#define C_QUEUE_H


#include <cstdlib>
#include <vector>
#include <string>

template <class T>
/** bad queue implementation: O(n) dequeue. */
class queue {
private:
    std::vector<T> data;
public:
    void enqueue(const T& item);
    T dequeue();
    bool isEmpty();
    size_t size();
};

template <class T>
void queue<T>::enqueue(T const &item) {
    data.push_back(item);
}

template <class T>
T queue<T>::dequeue() {
    auto res = data[0];
    data.erase(data.begin());
    return res;
}

template <class T>
bool queue<T>::isEmpty() {
    return data.empty();
}

template <class T>
size_t queue<T>::size() {
    return data.size();
}

std::string hotPotato(const std::vector<std::string> names, int num) {
    auto q = queue<std::string>();
    for (auto name : names) {
        q.enqueue(name);
    }

    while (q.size() > 1) {
        for (int i = 0; i < num; ++i) {
            q.enqueue(q.dequeue());
        }

        q.dequeue();
    }
    return q.dequeue();
}

#endif //C_QUEUE_H
