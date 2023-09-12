#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, a[200001], dp[200001];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 0;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] ^ a[i], a[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}