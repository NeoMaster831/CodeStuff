#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, m; cin >> n >> m;
    if (m % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (i-1) * m + j << ' ';
            }
            cout << '\n';
        }
    } else {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (i - 1) * m + ((j + i - 1) % m == 0 ? m : (j + i - 1) % m) << ' ';
            }
            cout << '\n';
        }
    }


}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}