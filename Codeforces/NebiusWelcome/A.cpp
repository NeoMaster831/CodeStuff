#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    
    int x, y; cin >> x >> y;
    x = abs(x); y = abs(y);
    bool same = x == y;
    int tosub = min(x, y);

    int ans = tosub * 2;
    x -= tosub; y -= tosub;
    ans += max(x, y) * 2;
    if (!same) ans -= 1;
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}