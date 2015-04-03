#include "main.h"
#include "stack.h"

#include <iostream>
#include <assert.h>

using namespace std;

int main() {

    testPop();
    testPush();
    testIsEmpty();
    testSize();


    return 0;
}

void testIsEmpty() {
    auto testee = stack<char>();
    assert(testee.isEmpty());

    testee.push(1);

    assert(!testee.isEmpty());
    cout << "testIsEmpty passed" << endl;
}

void testSize() {
    auto testee = stack<char>();

    assert(testee.size() == 0);

    testee.push(1);
    testee.push(2);

    assert(testee.size() == 2);
    cout << "testSize passed" << endl;
}

void testPush() {
    auto testee = stack<int>();
    testee.push(1);
    assert(testee.peek() == 1);
    testee.push(2);
    assert(testee.peek() == 2);
    testee.push(3);
    assert(testee.peek() == 3);
    assert(testee.size() == 3);
    cout << "testPush passed" << endl;
}

void testPop() {
    auto testee = stack<int>();
    testee.push(1);
    testee.push(2);
    testee.push(3);
    assert(testee.size() == 3);
    assert(testee.pop() == 3);
    assert(testee.size() == 2);
    cout << "testPop passed" << endl;
}

