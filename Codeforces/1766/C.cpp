#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
string S[2];

void solve() {
    cin >> N >> S[0] >> S[1];

    int end = N - 1;
    while (S[0][end] == 'W' && S[1][end] == 'W') end--;

    //cout << end << '\n';
    vector<int> startptr;
    if (S[0][0] == 'B') startptr.push_back(0);
    if (S[1][0] == 'B') startptr.push_back(1);

    bool ans = false;
    for (int p = 0; p < startptr.size(); p++) {
        
        bool subans = true;
        int start = startptr[p];
        for (int i = 0; i <= end; i++) {
            //cout << "(" << S[start][i] << ", " << i << "), ";
            if (S[start][i] == 'W') {
                subans = false; break;
            }
            if (S[0][i] == 'B' && S[1][i] == 'B') start = !start;
        }
        
        ans = ans | subans;
    }

    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}