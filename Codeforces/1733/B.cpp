#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, X, Y;

void solve() {

    cin >> N >> X >> Y;
    if ((Y != 0 && X != 0) || (X == 0 && Y == 0)) { cout << -1 << '\n'; return; }
    
    int divider = -1;
    if (X != 0) divider = X;
    if (Y != 0) divider = Y;

    if (N % divider != 1 && divider != 1) { cout << -1 << '\n'; return; }

    for (int i = 1; i <= divider; i++) {
        cout << 1 << ' ';
    }
    for (int i = 3; i <= N; i++) {
        if (i % divider == 0) {
            for (int k = 1; k <= divider; k++) {
                cout << i << ' ';
            }
        }
    }

    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}