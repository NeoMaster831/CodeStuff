#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, D[101];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    int sum = D[1];
    vector<int> ans;
    ans.push_back(D[1]);

    for (int i = 2; i <= N; i++) {
        if (D[i] != 0 && sum - D[i] >= 0) { cout << -1 << '\n'; return; }
        sum += D[i];
        ans.push_back(sum);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}