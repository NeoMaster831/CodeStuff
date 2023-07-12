#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;
    int pluscnt = 0, minuscnt = 0;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        if (inp == 1) pluscnt++;
        else minuscnt++;
    }
    //cout << pluscnt << ' ' << minuscnt << '\n';
    int ans = 0;
    while (pluscnt < minuscnt) {
        pluscnt++;
        minuscnt--;
        ans++;
    }
    if (minuscnt % 2 != 0) {
        ans++;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}