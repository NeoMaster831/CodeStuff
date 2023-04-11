#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
int n, m, k, x, y, z, u, v, r, g, res;
vector<int> dist, back, ra, visited, visited2;
vector<pair<int, int>> f;
vector<vector<pair<int, int>>> vt;
void dfs(int here, int dis) {
    visited[here] = 1;
    dist[here] = dis;
    if (dist[here] > r) {
        r = dist[here];
        v = here;
    }
    for (auto next : vt[here]) {
        if (visited[next.first])continue;
        dfs(next.first, dis + next.second);    
    }
}
void dfs2(int here, int dis) {
    visited2[here] = 1;
    dist[here] = dis;
    if (dist[here] > r) {
        r = dist[here];
        u = here;
    }
    for (auto next : vt[here]) {
        if (visited2[next.first])continue;
        dfs2(next.first, dis + next.second);
        back[next.first] = here;
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    vt.resize(n + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        vt[x + 1].push_back({ y + 1,z });
        vt[y + 1].push_back({ x + 1,z });
    }
    back.assign(n + 1, 0);
    dist.assign(n + 1, INF);
    visited.assign(n + 1, 0);
    visited2.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (visited[i])continue;
        r = 0;
        u = i;
        dfs(i, 0);
        r = 0;
        back[v] = 0;
        dfs2(v, 0);
        f.push_back({ u ,r });
        res = max(r, res);
    }
    for (auto next : f) {
        int it = next.first;
        g = INF;
        while (it) {
            int rad = max(dist[it], next.second - dist[it]);
            g = min(g, rad);
            it = back[it];
        }
        ra.push_back(g);
    }
    sort(ra.rbegin(), ra.rend());
    if (ra.size() >= 2) 
        res = max(res, ra[0] + ra[1] + k);
    if (ra.size() >= 3)
        res = max(res, ra[1] + ra[2] + 2 * k);
    printf("%d\n", res);
    return 0;
}