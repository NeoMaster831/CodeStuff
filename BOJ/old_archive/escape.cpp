#include <bits/stdc++.h>

using namespace std;

int N, K, dp[300001];
vector<int> tree[300001];

int dfs(int node, int last, bool fir) {

    int& cache = dp[node];

    if (tree[node].size() == 1 && !fir) { // Base case: leaf node
        cache = 1; return 1;
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < tree[node].size(); i++) {

        int nxt = tree[node][i];
        if (nxt == last) continue;

        int ret = dfs(nxt, node, false);
        pq.push(ret);
        cache += dp[nxt];
    }

    // First case: 자식 -> X -> 자식
    int t = pq.top(); pq.pop();

    //cout << "Node: " << node << "\'s min: " <<  t << '\n';
    if (!pq.empty()) {
        int s = pq.top();
        if (t + s <= K) {
            cache--; return K + 1;
        }
    }

    // Second case: 자식 -> X (경로 수식)
    if (t <= K) {
        return t + 1;
    }

    // Edge case: All zero
    cache++; return 1;
}

int main() {

    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int from, to; cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(1, 0, true);
    
    /*
    for (int i = 1; i <= N; i++) {
        cout << "Node " << i << "\'s dp: " << dp[i] << '\n';
    }
    */

   
    cout << dp[1] << '\n';
}