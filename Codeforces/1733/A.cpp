#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, K, A[101];

void solve() {

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }


    vector<int> ans;
    for (int i = 0; i < K; i++) {
        
        int maxi = 0;
        for (int j = 1 + i; j <= N; j += K) {
            maxi = max(A[j], maxi);
        }

        ans.push_back(maxi);
    }

    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
    }

    cout << sum << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}