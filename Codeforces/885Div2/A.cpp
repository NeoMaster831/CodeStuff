#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m, k, x, y;

void solve() {
    cin >> n >> m >> k >> x >> y;

    bool whit = true; x--; y--;
    if (y % 2 == x % 2) whit = false;
    
    int white = 0, black = 0;
    for (int i = 1; i <= k; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (a % 2 == b % 2) white++;
        else black++;
    }

    if ((!whit && white >= 1) || (whit && black >= 1)) cout << "NO" << '\n';
    else cout << "Yes" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}