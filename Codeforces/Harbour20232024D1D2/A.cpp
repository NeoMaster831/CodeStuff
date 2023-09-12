#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main() {

    int seconds = rand() + 1;
    cout << seconds << '\n';
    rand();
    rand();
    cout << rand() << '\n';
}