#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k, a[200001];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp; a[i] = (inp - 1) % k;
    }

    vector<pair<int, int> > ans;
    for (int i = 1; i <= n; i++) {
        if ((i - 1) % k != a[i]) {
            ans.push_back({(i - 1) % k, a[i]});
        }
    }
    if (ans.size() == 0 ) {
        cout << 0 << '\n'; return;
    }
    if (ans.size() != 2) {
        cout << -1 << '\n'; return;
    }
    if (ans[0].first == ans[1].second && ans[0].second == ans[1].first) {
        cout << 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}