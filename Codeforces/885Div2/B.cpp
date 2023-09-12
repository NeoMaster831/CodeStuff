#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k, last[200001];
priority_queue<int> pq[200001];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        last[i] = 0;
        while (!pq[i].empty()) pq[i].pop();
    }
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        pq[inp].push(i - (last[inp] + 1));
        last[inp] = i;
    }

    for (int i = 1; i <= k; i++) {
        pq[i].push((n + 1) - (last[i] + 1));
    }

    int ans = 987654321234567;
    for (int i = 1; i <= k; i++) {
        int t = pq[i].top(); pq[i].pop();
        int s = pq[i].empty() ? 0 : pq[i].top();
        //cout << i << ' ' << t << ' ' << s << '\n';
        ans = min(ans, max(t / 2, s));
    }

    cout << ans << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}