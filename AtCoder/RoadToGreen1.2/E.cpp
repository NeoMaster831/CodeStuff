#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 98765432123345

int N, M, A[200001], maxarr[200001], ans = -INF;
vector<int> graph[200001];
bool chk[200001];

int dfs(int node) {

    if (graph[node].size() == 0) {
        return maxarr[node] = A[node];
    }

    if (chk[node]) {
        return maxarr[node];
    }

    chk[node] = true;
    
    int maxi = -1;
    for (int i = 0; i < graph[node].size(); i++) {

        int nxt = graph[node][i];

        int rt = dfs(nxt);

        maxi = max(rt, maxi);
    }
    
    ans = max(maxi - A[node], ans);
    maxi = max(A[node], maxi);

    return maxarr[node] = maxi;
}

signed main() {

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; i++) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
    }

    for (int i = 1; i <= N; i++) {
        dfs(i);
    }

    cout << ans << '\n';
}