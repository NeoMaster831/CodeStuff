#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INITIAL make_pair(9876543222345678LL, 12341234123412LL)

int N, k;
vector<int> tree[200001];
//    
pair<int, int> dfs(int node, int bf) {

    if (tree[node].size() == 1 && bf != -1) { // not the first, but leaf
        return { 0, 1 };
    }

    int x = 0;
    int y = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (nxt == bf) continue;
        auto res_t_ = dfs(nxt, true, node);
        auto res_f = dfs(nxt, false, node);
        if (res_f.second == k && !patch) res_f = res_t_;

        auto res = min(res_t_, res_f);
        x += res.first;
        y = max(y, res.second);
    }

    return { x + patch, patch ? 1 : y + 1 };
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> k;
    for (int i = 1; i <= N - 1; i++) {
        int from, to; cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i][1] = INITIAL;
    }
    
    auto ans = min(dfs(1, true, -1), dfs(1, false, -1));
    cout << ans.first << '\n';
}