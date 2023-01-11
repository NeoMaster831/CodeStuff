#include <bits/stdc++.h>

using namespace std;

// Using postorder method

int N, cnt;
vector<int> tree[200001];
pair<int, int> S[200001];
bool chk[200001];

pair<int, int> postorder(int node, bool fir) {

    chk[node] = true;
    if (!fir && tree[node].size() == 1) {
        cnt++; S[node] = { cnt, cnt };
        return S[node];
    }

    int mini = 999999, maxi = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (chk[nxt]) continue;

        pair<int, int> val = postorder(nxt, false);
        mini = min(val.first, mini);
        maxi = max(val.second, maxi);
    }

    S[node] = { mini, maxi };
    return S[node];
}

int main() {

    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        int from, to; cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    postorder(1, true);

    for (int i = 1; i <= N; i++) {
        cout << S[i].first << ' ' << S[i].second << '\n';
    }
}