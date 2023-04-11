#include <bits/stdc++.h>

using namespace std;
#define int long long


/*
25, 14, 11, 10
1, 2, 3, 4, 6, 8, 12, 24

17, 10, 8
1, 2, 4, 8, 16
*/


vector<int> yaksu(int x) {

    vector<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            res.push_back(x / i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

void solve() {

    int A, B; cin >> A >> B;
    vector<int> fA = yaksu(A), fB = yaksu(B);

    int ans = 1249214921439;
    for (int i = 0; i < fA.size(); i++) {
        int chosen = fA[i];
        int preans = chosen - 1 + fA[fA.size() - 1 - i];
        int idx = lower_bound(fB.begin() + fB.size() / 2 - 1, fB.end(), chosen) - fB.begin();
        if (idx >= fB.size()) break;

        int val = fB[idx];

        preans += val - chosen;
        preans += B / val;
        ans = min(ans, preans);
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while (T--) solve();
}