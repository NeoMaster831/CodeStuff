#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, Q, parent[250001], parent_u[250001], cnt[250001];
bool inS[250001], chk[250001];
vector<int> tree[250001];

int combination2(int x) { // xC2
    return x * (x - 1) / 2;
}

int Find(int x) {
    if (parent_u[x] == x) return x;
    return parent_u[x] = Find(parent_u[x]);
}

void Union(int x, int y) {
    //cout << "Union Operation: x: " << x << ", y: " << y << '\n';
    x = Find(x); y = Find(y);
    if (x != y) parent_u[x] = y;
}

void dfs(int node, int last) {
    chk[node] = true;

    parent[node] = last;
    for (int i = 0; i < tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (chk[nxt]) continue;
        dfs(nxt, node);
    }
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) { parent[i] = i; parent_u[i] = i; }
    for (int i = 1; i <= N - 1; i++) {
        int from, to; cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(1, 1);
    //for (int i = 1; i <= N; i++) cout << "Parent[" << i << "]: " << parent[i] << '\n';

    cin >> Q;
    while (Q--) {

        int K; cin >> K; vector<int> S;
        for (int i = 0; i < K; i++) {
            int inp; cin >> inp; S.push_back(inp);
        }

        //cout << "S.size = " << S.size() << '\n';

        int ans = 0;
        for (int i = 0; i < K; i++) inS[S[i]] = true;
        for (int i = 0; i < K; i++) 
            if (inS[parent[S[i]]]) Union(S[i], parent[S[i]]);
        for (int i = 0; i < K; i++) parent_u[S[i]] = Find(parent_u[S[i]]);
        for (int i = 0; i < K; i++) cnt[parent_u[S[i]]]++;

        /*
        for (int i = 0; i < K; i++) {
            cout << "Parent(U)[" << S[i] << "]: " << parent_u[S[i]] << '\n';
        }
        */

        for (int i = 0; i < K; i++) {
            ans += combination2(cnt[S[i]]);
        }

        cout << ans << '\n';

        // Last: Initialize
        for (int i = 0; i < K; i++) {
            //int node = S[i];
            parent_u[S[i]] = S[i];
            cnt[S[i]] = 0;
            inS[S[i]] = false;
        }
    }
}