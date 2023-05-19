#include <bits/stdc++.h>

using namespace std;
#define int long long

int dx[8] = { 'h','g','f','e','d','c','b','a' };
string inp[8];

signed main() {

    for (int i = 0; i < 8; i++) {
        cin >> inp[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (inp[i][j] == '*') {
                cout << (char)dx[8 - j - 1] << 8 - i;
            }
        }
    }
}