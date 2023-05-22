#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, x, y;

signed main() {

    cin >> N >> x >> y;
    if (N == 1) cout << 0 << '\n';
    else if ((x == y && (x == 1 || x == N)) || (x == 1 && y == N) || (x == N && y == 1)) cout << 2 << '\n';
    else if (x == 1 || y == 1 || x == N || y == N) cout << 3 << '\n';
    else cout << 4 << '\n';
}