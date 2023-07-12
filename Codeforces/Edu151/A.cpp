#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (x != 1) {
        cout << "yEs" << '\n';
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
    if (k == 1) {
        cout << "No" << '\n';
    } else if (k == 2) {
        if (n % 2 == 0) {
            cout << "Yes" << '\n';
            cout << n / 2 << '\n';
            for (int i = 1; i <= n / 2; i++) {
                cout << 2 << ' ';
            }
            cout << '\n';
        } else {
            cout << "nO" << '\n';
        }
    } else {
        if (n != 1) {
            cout << "YES" << '\n';
            if (n % 2 == 0) {
                cout << n / 2 << '\n';
                for (int i = 1; i <= n / 2; i++) {
                    cout << 2 << ' ';
                }
                cout << '\n';
                return;
            }
            cout << (n / 3) + 1 - (n % 3 == 0) << '\n';

            while (n >= 3) {
                cout << 3 << ' ';
                n -= 3;
            }
            if (n != 0) {
                cout << 2 << ' ';
            }
            cout << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}