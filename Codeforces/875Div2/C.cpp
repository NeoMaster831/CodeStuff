#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
vector<int> edges[200001][2];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        edges[i][0].clear(); edges[i][1].clear();
    }
    
    set<int> found;
    found.insert(1);
    for (int i = 1; i <= N - 1; i++) {
        int from, to; cin >> from >> to;
        bool res = found.find(from) != found.end();
        edges[from][res].push_back(to);
        found.insert(to);
    }

    int ans = 0;
    queue<pair<pair<int, int>, int> > q;
    q.push({{1, 1}, 1});
    while (!q.empty()) {
        int node = q.front().first.first;
        int huwi = q.front().first.second;
        int stage = q.front().second;
        ans = max(ans, stage);
        q.pop();
        //cout << node << ' ' << huwi << ' ' << stage << '\n';
        for (auto x : edges[node][huwi]) {
            q.push({{x, 1}, stage});
        }

        if (huwi == 1 && edges[node][0].size() != 0) q.push({{node, 0}, stage + 1});
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}