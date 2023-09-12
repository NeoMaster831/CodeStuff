#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int N; cin >> N;
    map<int, int> m;
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        int inp; cin >> inp;
        auto x = m.find(inp);
        if (x != m.end()) {
            int nv = x->second + 1;
            m.erase(inp);
            m.insert({inp, nv});
        } else {
            m.insert({inp, 1});
        }
    }

    vector<int> ans;
    for (int i = N - 1; i >= 1; i--) {
        auto x = m.begin();
        ans.push_back(x->first);
        x->second -= i;
        if (x->second <= 0) {
            m.erase(x->first);
        }
    }
    ans.push_back((int)1E9);
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