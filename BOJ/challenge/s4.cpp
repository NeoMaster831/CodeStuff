#include <bits/stdc++.h>

using namespace std;
#define int long long

int ans[1001];

signed main() {
    int n; cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int > > > pq;
    for (int i = 0; i < n; i++) {
        int inp; cin >> inp;
        pq.push({inp, i});
    }

    int o = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        ans[t.second] = o++;
        pq.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}