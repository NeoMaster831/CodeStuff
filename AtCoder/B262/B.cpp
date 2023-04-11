#include <bits/stdc++.h>

using namespace std;

int N, M, ans, graph[101][101];
bool chk[101];

void dfs(int node) {

    chk[node] = true;

    vector<int> cnted;
    for (int i = 1; i <= N; i++) {
        
        if (chk[i] == true) continue;

        int can = graph[node][i];
        if (can == 0) continue;

        cnted.push_back(i);
        dfs(i);
    }

    for (int i = 0; i < cnted.size(); i++) {
        for (int j = i + 1; j < cnted.size(); j++) {
            int from = cnted[i];
            int to = cnted[j];
            if (graph[from][to] == 1) ans++;
        }
    }
}

int main() {

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int from, to; cin >> from >> to;
        graph[from][to] = 1;
    }

    dfs(1, 0);
    cout << ans << '\n';
}