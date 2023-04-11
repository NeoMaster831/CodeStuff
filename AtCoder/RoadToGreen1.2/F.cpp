#include <bits/stdc++.h>

using namespace std;

int N, M, dp[8][(1 << 8)];
vector<int> graph[8];

/*
BEWARE: You should turn on the bitmask when you visited the node;
You should preprocess it.
*/

int dfs(int node, int status) {

    int& cache = dp[node][status];
    if (cache != -1) {
        return cache;
    }
    if (status == (1 << N) - 1) { // All visited
        return cache = 1;
    }

    int GyungWoo = 0;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (status & (1 << nxt)) continue;
        int newstat = status | (1 << nxt);
        int rt = dfs(nxt, newstat);

        GyungWoo += rt;
    }

    return cache = GyungWoo;
}

int main() {

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int from, to; cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 1) << '\n';
}