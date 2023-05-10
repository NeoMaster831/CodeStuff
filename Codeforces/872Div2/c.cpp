#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M, X[100001];

void solve() {

    cin >> N >> M;

    int lm = 0, rm = 0;

    set<int> jungbok;
    vector<int> newv;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
        if (X[i] == -1) lm++;
        else if (X[i] == -2) rm++;
        else if (jungbok.find(X[i]) == jungbok.end()) {
            newv.push_back(X[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < newv.size(); i++) {
        int lcan = newv[i] - i - 1;
        int rcan = M - newv[i] - (newv.size() - i - 1);

        // 1. 된다면
        if (lcan >= lm && rcan >= rm) {
            ans = max(ans, lm + rm + newv.size());
        }
        // 2. 모두 안 된다면
        if (lcan < lm && rcan < rm) {
            ans = max(ans, M);
        }
        if (lcan >= lm && rcan < rm) {
            // 3-1. lm 모두 채우기
            int lidxcan = i, ridxcan = newv.size() - i - 1;
            ans = max(ans, lm + lidxcan + 1 + (M - newv[i]));
            // 3-2. rm 채우고 lm 버리기
        }
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}