#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m, a[200001];
string s;

void solve() {
    cin >> n >> m;
    cin >> s;

    int c = 0;
    for (int i = 0; i < n; i++) {
        a[i] = c;
        if (i == n - 1) continue;
        if (s[i] == '1' && s[i + 1] == '0') c++;
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r; l--; r--;
        if (a[l] != a[r]) ans++;
    }

    cout << ans << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}