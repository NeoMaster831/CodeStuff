#include <bits/stdc++.h>

using namespace std;

int Y;

int main() {
    cin >> Y;
    int fY = Y / 4;
    if (Y % 4 == 3) fY++;

    cout << fY * 4 + 2;
}