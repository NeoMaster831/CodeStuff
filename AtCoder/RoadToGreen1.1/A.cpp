#include <bits/stdc++.h>

using namespace std;

int X;

int main() {

    cin >> X;
    if (X % 100 == 0) cout << 100 << '\n';
    else cout << 100 - (X % 100) << '\n';
}