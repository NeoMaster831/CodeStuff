#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int b, c, h; cin >> b >> c >> h;
    if (c + h >= b) {
        cout << b * 2 - 1 << '\n';
    } else {
        cout << (c + h) * 2 + 1 << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}