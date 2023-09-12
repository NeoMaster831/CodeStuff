#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k;

void solve() {
    cin >> n >> k;
    priority_queue<int> pq;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        if (last != -1) pq.push(abs(inp - last));
        last = inp;
    }


    for (int i = 1; i < k; i++) {
        if (pq.empty()) break; pq.pop();
    }

    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top(); pq.pop();
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}