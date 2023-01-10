#include <bits/stdc++.h>

using namespace std;
#define int long long

int N; pair<int, int> A[100001];

void solve() {
    
    cin >> N;

    int mini = 98765432123456;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp; A[i] = { inp, i };
    }

    sort(A + 1, A + N + 1);

    vector<pair<int, int> > ans;
    for (int i = 2; i <= N; i++) {
        int prev = A[i - 1].first;
        int val = A[i].first;
        int idx = A[i].second;

        if (val % prev == 0) continue;
        int haveto = prev - (val % prev);

        ans.push_back({ idx, haveto });
        A[i] = { val + haveto, idx };
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}