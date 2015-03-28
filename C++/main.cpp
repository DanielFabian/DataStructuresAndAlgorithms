#include <iostream>

using namespace std;

int sum_of_n(int n);

int main() {
    cout << "Hello, World!" << endl;
    cout << sum_of_n(10) << endl;
    return 0;
}

int sum_of_n(int n)
{
    auto res = 0;
    for (int i = 1; i <= n; i++) {
        res += i;
    }

    return res;
}