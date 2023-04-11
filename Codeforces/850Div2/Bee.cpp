#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, W, H, A[100001], B[100001];

void solve() {
    
    cin >> N >> W >> H;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    vector<pair<int, int> > edges;
    for (int i = 1; i <= N; i++) {
        edges.push_back({A[i] - W + H - B[i], 0});
        edges.push_back({A[i] + W - H - B[i], 1});
    }
    
    sort(edges.begin(), edges.end());
    
    bool ans = false; int stack_size = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (stack_size == N) ans = true;
        if (edges[i].second == 1) break;
        else stack_size++;
    }

    if (ans) cout << "yEs" << '\n';
    else cout << "nO" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}