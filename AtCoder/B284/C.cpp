#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[101];
bool chk[101];

bool dfs(int node) {

    if (chk[node]) return false;
    chk[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        dfs(nxt);
    }

    return true;
}

int main() {

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        bool ischk = dfs(i);
        ans += ischk;
    }

    cout << ans << '\n';
}