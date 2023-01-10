#include <bits/stdc++.h>

using namespace std;

//              node,   dist
int V; vector<pair<int, int> > tree[100001];
bool chk[100001]; int maxi[100001];
int ans = -1;

int dfs(int node, bool fir) {

    chk[node] = true;
    if (tree[node].size() == 1 && !fir) return 0; // Base case: leaf node

    priority_queue<int> pq;
    for (int i = 0; i < tree[node].size(); i++) {

        int nxt = tree[node][i].first;
        int dist = tree[node][i].second;
        if (chk[nxt]) continue;

        int mxd = dfs(nxt, false) + dist; pq.push(mxd);

    }

    //cout << "Node: " << node << ", pq size: " << pq.size() << ", Max: " << pq.top() << '\n'; 
    maxi[node] = pq.top(); pq.pop();
    if (!pq.empty()) ans = max(ans, maxi[node] + pq.top());

    return maxi[node];
}

int main() {
    

    cin >> V;
    for (int i = 1; i <= V; i++) {
        int node; cin >> node;
        
        while (true) {
            int inp; cin >> inp; if (inp == -1) break;
            int dist; cin >> dist;
            tree[node].push_back({inp, dist});
        }
    }


    ans = max(ans, dfs(1, true)); cout << ans << '\n';
}