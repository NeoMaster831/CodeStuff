#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    int a[21];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int k = 1;
    while (k < n) {
        k *= 2;
    }

    if (k != n) k /= 2;
    
    for (; k > 0; k /= 2) {
        if (k + 1 > n) continue;
        int d = a[k + 1];
        for (int j = k + 2; j <= min(n, k * 2); j++) {
            if (d > a[j]) {
                cout << "NO" << '\n'; return;
            }
            else {
                d = a[j];
            }
        }
    }
    cout << "YES" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}