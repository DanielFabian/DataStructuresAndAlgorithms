//
// Created by Daniel on 06.04.2015.
//

#include "deque.h"

bool palchecker(std::string word) {
    auto chars = deque<char>();

    for(auto c : word) {
        chars.addRear(c);
    }

    while(chars.size() > 1) {
        if(chars.removeFront() != chars.removeRear()) {
            return false;
        }
    }

    return true;
}
