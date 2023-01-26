#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M, P[50001][11];
vector<int> tree[11][11];

int dfs(int newp[11], int depth) {
    
    if (depth == M) return 1;

    int n = newp[depth];
    int tofind = newp[depth + 1];

    //cout << "Now: " << n << ", To Find: " << tofind << '\n';
    int ret = 0;
    for (int i = 0; i < tree[depth][n].size(); i++) {
        int nxt = tree[depth][n][i];
        if (nxt != tofind) continue;
        ret = max(ret, dfs(newp, depth + 1) + 1);
    }

    return ret;
}

void solve() {

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> P[i][1];

        int bef = P[i][1];
        for (int j = 2; j <= M; j++) {
            cin >> P[i][j];
            tree[j - 1][bef].push_back(P[i][j]);
            bef = P[i][j];
        }

    }
    for (int i = 1; i <= N; i++) {

        int newp[11];
        for (int j = 1; j <= M; j++) {
            int pj = P[i][j];
            newp[pj] = j;
        }
        cout << dfs(newp, 1) << ' ';
    }

    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}