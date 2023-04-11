#include <bits/stdc++.h>

using namespace std;
#define int long long

string PI = "314159265358979323846264338327";
string S;

void solve() {
    
    cin >> S;

    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != PI[i]) break;
        cnt++;
    }

    cout << cnt << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}