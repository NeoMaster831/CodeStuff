#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;
vector<int> graph[200001];
bool chk[200001];

int dfs(int node, bool first) {

    if (chk[node]) return 0;

    chk[node] = true;
    if (!first && graph[node].size() == 1) return 1;
    
    int res = 0;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        res += dfs(nxt, false);
    }

    return res;
}

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int ret = dfs(1, true);
    if (ret + (graph[1].size() == 1) == 2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}