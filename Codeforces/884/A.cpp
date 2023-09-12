#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int a, b; cin >> a >> b;
    if (a == 1 || b == 1) cout << a + b << '\n';
    else cout << 1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}