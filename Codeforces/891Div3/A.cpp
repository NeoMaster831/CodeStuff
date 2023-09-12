#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int N; cin >> N;
    int odds = 0;
    for (int i = 0; i < N; i++) {
        int inp; cin >> inp; if (inp % 2) odds++;
    }
    if (odds % 2) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}