#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 300000

int N, cnt = 1;
map<string, int> m;
int link[MAXN], discovered[MAXN], node_order, cycle;
bool finished[MAXN];

void dfs(int node)
{
    discovered[node] = node_order++;

    int nxt = link[node];
    if (link[node] == 0) return;

    if (discovered[nxt] == -1)
        dfs(nxt);
    else if (!finished[nxt])
        ++cycle;

    finished[node] = true;
}

signed main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string from, to; cin >> from >> to;
        auto fnode = m.find(from), tnode = m.find(to);
        
        int f, t;
        if (fnode == m.end()) { f = cnt; m.insert({ from, cnt }); cnt++; }
        else f = fnode->second;
        if (tnode == m.end()) { t = cnt; m.insert({ to, cnt }); cnt++; }
        else t = tnode->second;
        link[f] = t;

    }

    for (int i = 0; i <= cnt; i++) discovered[i] = -1;
    for (int i = 1; i <= cnt; i++) {
        if (!finished[i]) dfs(i);
    }

    if (cycle == 0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}