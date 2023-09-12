#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int mid = n / 2 + (n % 2);

    int ans = 0;
    int i, j;
    for (i = 1; i <= mid; i += k) {
        if (i == mid) break;
        ans++;
    } i -= k;
    for (j = n; j >= mid; j -= k) ans++; j += k;
    if (j - i > k) ans++;

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}