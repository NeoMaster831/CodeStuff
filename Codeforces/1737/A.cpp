#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, K, cnt[26];
string S;

void solve() {
    
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    cin >> N >> K >> S;
    for (int i = 0; i < N; i++) {
        cnt[S[i] - 97]++;
    }
    
    vector<char> ans;
    for (int i = 0; i < K; i++) {
        int can = 97;
        for (int j = 0; j < N / K; j++) {
            if (cnt[j] == 0) break;
            cnt[j]--; can++;
        }

        ans.push_back(can);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}