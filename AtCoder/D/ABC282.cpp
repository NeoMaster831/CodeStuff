#include <bits/stdc++.h>

using namespace std;
#define int long long

int indegree[200002], d[200002], cnt[2];
bool chk[200002];
vector<int> graph[200002];
int N, M;

void bfs(int start) {

    queue<pair<int, int> > q;
    q.push({start, 0});

    while (!q.empty()) {
        
        pair<int, int> fr = q.front();
        int depth = fr.second;
        int node = fr.first;
        q.pop();

        if (chk[node]) continue;
        chk[node] = true;

        for (int i = 0; i < graph[node].size(); i++) {
            int nxt = graph[node][i];
            q.push({nxt, depth + 1});
        }

        d[node] = depth;
    }

}

bool dfs(int node, bool color) {

}

signed main() {
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 1; i <= N; i++) chk[i] = false;
    bfs(1);
    
    for (int i = 1; i <= N; i++) {

        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j];
            if (d[i] % 2 != d[nxt] % 2) indegree[i]++;
        }
        
        cnt[d[i] % 2]++;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int t = !(d[i] % 2);
        ans += cnt[t] - indegree[i];
    }

    cout << ans / 2 << '\n';
}