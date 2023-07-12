#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    string S, T; cin >> S >> T;
    string G = S;
    reverse(G.begin(), G.end());

    int g_tnm = 0;
    for (int i = 0; i < n; i++) {
        if (G[i] != T[i]) {
            g_tnm++;
        }
    }
    int s_tnm = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) s_tnm++;
    }

    int ptr = 1;
    int ans = 0;
    while (1) {
        if ((ptr % 2 == 1 && s_tnm <= 0) || (ptr % 2 == 0 && g_tnm <= 0)) break;
        s_tnm--; // 1번경우
        g_tnm--; // 2번경우
        ans++;
        if ((ptr % 2 == 1 && s_tnm <= 0) || (ptr % 2 == 0 && g_tnm <= 0)) break;
        ans++;
        ptr++;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}