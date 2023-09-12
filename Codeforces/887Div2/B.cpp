#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k;
pair<int, int> dp[33];

void solve() {
    cin >> n >> k;
    if (k > 32) {
        if (n == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }

    int a = dp[k].first;
    int b = dp[k].second;

    // ax + by = c
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int c = n - a * i;
        if (c % b == 0) {
            if (c / b < i) continue;
            ans++;
        }
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    dp[1] = { 1, 0 };
    dp[2] = { 0, 1 };
    for (int i = 3; i <= 32; i++) {
        dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
        //cout << dp[i].first << ' ' << dp[i].second << ' ' << i << '\n';
    }

    int T; cin >> T;
    while (T--) solve();
}