#include <bits/stdc++.h>

using namespace std;
#define int long long

priority_queue<int> pq[200001];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while (!pq[i].empty()) pq[i].pop();
    }
    
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        pq[a].push(b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        while (!pq[i].empty() && cnt < i) {
            ans += pq[i].top(); pq[i].pop();
            cnt++;
        }
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}