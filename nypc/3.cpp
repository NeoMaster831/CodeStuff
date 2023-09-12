#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pp pair<int, pair<int, int> >

struct Edge {
public:
    int to,from,  w;
    int* c;
    Edge(int f, int t, int w, int* c) {
        this->from = f;
        this->to = t;
        this->w = w;
        this->c = c;
    }
};

int a[200001];
int _count[200001];
vector<Edge> graph[200001];
vector<int> ind[200001];
bool chk[200001];
int shit[200001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= s; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w, c; cin >> u >> v >> w >> c;
        _count[i] = c;
        graph[u].push_back(Edge(u, v, w, &_count[i]));
        graph[v].push_back(Edge(v, u, w, &_count[i]));
        for (int j = 1; j <= c; j++) {
            int inp; cin >> inp;
            ind[inp].push_back(i);
        }
    }

    for (int i = 1; i <= s; i++) {
        for (int j = 0; j < ind[a[i]].size(); j++) {
            _count[ind[a[i]][j]]--;
        }
        ind[a[i]].clear();
    }

    queue<int> q;
    q.push(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (*graph[i][j].c != 0) shit[i]++;
        }
    }

    int cnt = 0;
    while (!q.empty()) {

        int node = q.front(); q.pop();
        for (int i = 0; i < graph[node].size(); i++) {
            auto edge = graph[node][i];
            if (shit[node] == 0) continue;
            //cout << *edge.c << ' ' << edge.to << ' ' << edge.w << '\n';
            if (*edge.c == 0) {
                for (int j = 0; j < ind[edge.w].size(); j++) {
                    _count[ind[edge.w][j]]--;
                }
                ind[edge.w].clear();
                q.push(edge.to);
                shit[node]--;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += chk[i];
    }

    cout << ans << '\n';
}