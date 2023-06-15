#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200001], B[200001];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    map<int, int> m;
    int val = 0, strike = 0;
    for (int i = 1; i <= N; i++) {
        if (val != A[i]) {
            val = A[i];
            strike = 1;
        } else {
            strike++;
        }
        if (m.find(val) == m.end() || m.find(val)->second < strike) {
            m.erase(val);
            m.insert({val, strike});
        }
    }

    map<int, int> m2;
    val = 0; strike = 0;
    for (int i = 1; i <= N; i++) {
        if (val != B[i]) {
            val = B[i];
            strike = 1;
        } else {
            strike++;
        }
        if (m2.find(val) == m2.end() || m2.find(val)->second < strike) {
            m2.erase(val);
            m2.insert({val, strike});
        }
    }

    int ans = 0;
    for (auto iter : m) {
        int val = iter.first, strike = iter.second;
        //cout << val << ' ' << strike << '\n';
        auto k = m2.find(val);
        if (k != m2.end()) strike += k->second;
        ans = max(ans, strike);
    }
    for (auto iter : m2) {
        int val = iter.first, strike = iter.second;
        //cout << val << ' ' << strike << '\n';
        auto k = m.find(val);
        if (k != m.end()) strike += k->second;
        ans = max(ans, strike);
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}