#include <bits/stdc++.h>

using namespace std;

signed main() {
    int a; string b;
    cin >> a >> b;

    int fir = a * (b[2] - 48);
    int sec = a * (b[1] - 48);
    int third = a * (b[0] - 48);
    int last = third * 100 + sec * 10 + fir;

    cout << fir << '\n' << sec << '\n' << third << '\n' << last << '\n';
}