#include <bits/stdc++.h>

using namespace std;

// Dedicated to suzuki-san, my waifu.

int N, K, parent[100001], depth[100001];
vector<int> tree[100001];
bool chk[100001], jiphap[100001];

int Find(int n) {
    if (parent[n] == n) return n;
    parent[n] = Find(parent[n]);
    return parent[n];
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a != b) parent[b] = a;
}

void depth_cache(int node, int d) {
    chk[node] = true;
    depth[node] = d;
    for (int i = 0; i < tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (!chk[nxt]) depth_cache(nxt, d + 1);
    }
}

int dfs(int node) {

    chk[node] = true;

    // Leaf node case
    if (tree[node].size() == 1) {
        jiphap[node] = true; return node;
    }

    pair<int, int> to_ret = { 0, 999999 };
    for (int i = 0; i < tree[node].size(); i++) {

        int nxt = tree[node][i];
        if (chk[nxt]) continue;

        int lfn = dfs(nxt);
        if (lfn == 0) continue;

        if (depth[node] >= (int)ceil(float(depth[lfn]) / 2.0f)) {
            Union(node, lfn);
            jiphap[node] = true;

            if (to_ret.second > depth[lfn]) { // update min
                to_ret = { lfn, depth[lfn] };
            }
        }
    }

    return to_ret.first;
}

void union_jiphaps(int node, int to) {
    
    chk[node] = true;
    if (to != 0 && jiphap[node]) {
        Union(node, to);
    }

    if (jiphap[node]) to = node;
    for (int i = 0; i < tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (chk[nxt]) continue;
        union_jiphaps(nxt, to);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int from, to; cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    // Edge case: if K is leaf node
    if (tree[K].size() == 1) { cout << 1; return 0; }

    depth_cache(K, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        chk[i] = false;
    }

    /*
    for (int i = 1; i <= N; i++) {
        cout << "depth[" << i << "]: " << depth[i] << '\n';
    }
    */

    dfs(K);
    for (int i = 1; i <= N; i++) chk[i] = false;
    

    union_jiphaps(K, 0);

    /*
    for (int i = 1; i <= N; i++) {
        cout << "parent[" << i << "]: " << parent[i] << ", Jiphap?:" << jiphap[i] << '\n';
    }
    */

    set<int> ans;
    for (int i = 1; i <= N; i++) {
        if (jiphap[i]) {
            ans.insert(Find(i));
        }
    }

    cout << ans.size() << '\n';
}