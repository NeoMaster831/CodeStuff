#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string l, r; cin >> l >> r;
    while (l.size() > r.size()) {
        r = "0" + r;
    } while (l.size() < r.size()) {
        l = "0" + l;
    }
    int ptr = 0;
    while (l[ptr] == r[ptr] && ptr != l.size()) ptr++;
    //cout << ptr << '\n';
    if (ptr == l.size()) {
        cout << 0 << '\n'; return;
    }
    int ans = abs(l[ptr] - r[ptr]);
    ptr++;
    ans += 9 * (l.size() - ptr);
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}