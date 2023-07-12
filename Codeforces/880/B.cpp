#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, k, g; cin >> n >> k >> g;
    int l = k * g, pigam = g / 2 + (g % 2 == 0);
    if ((l / pigam) + (l % pigam != 0) <= n) {
        cout << l << '\n';
    } else {
        int ans = pigam * (n - 1);
        int pl = (l - ans) % g;
        if (pl >= g / 2 + (g % 2 != 0)) {
            ans -= pigam;
        } else {
            ans += pl;
        }
        cout << ans << '\n';
    }
}

signed main() {
    int T; cin >> T;
    while (T--) solve();
}