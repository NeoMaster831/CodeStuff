#include <iostream>

using namespace std;

int main() {

    int a = 1;
    int b = 2;

    int* ptr1 = &a;
    int* ptr2 = (int*)&ptr1;

    *ptr2 = (int)&b;

    cout << *ptr1 << '\n';
}