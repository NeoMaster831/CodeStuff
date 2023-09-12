#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007

int n, a[200001], b[200001];

int modmul(int q, int r) {
    return ((q % MOD) * (r % MOD)) % MOD;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater<int>());

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int x = upper_bound(a + 1, a + n + 1, b[i]) - a;
        //cout << i << ' ' << x << '\n';
        ans = modmul(ans, max(0LL, n - x + 1 - i + 1));
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}