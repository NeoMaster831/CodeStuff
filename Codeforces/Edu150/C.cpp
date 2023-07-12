#include <bits/stdc++.h>

using namespace std;
#define int long long

int regexx[5] = { 1, 10, 100, 1000, 10000 };

void solve() {
    string s; cin >> s;
    s += "0";
    int delta = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] > s[i + 1]) {
            //cout << s[i] << ' ' << "large" << '\n';
            delta += regexx[s[i] - 65];
        } else {
            //cout << s[i] << ' ' << "small" << '\n';
            delta -= regexx[s[i] - 65];
        }
    }
    //cout << delta << '\n';

    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        int maxdt = delta;
        for (int j = 0; j < 5; j++) {
            int imsidt = delta;
            char to_change = j + 65;
            if (s[i] > s[i + 1]) {
                imsidt -= regexx[s[i] - 65];
            } else {
                imsidt += regexx[s[i] - 65];
            }
            if (to_change > s[i + 1]) {
                imsidt += regexx[j];
            } else {
                imsidt -= regexx[j];
            }
            if (i == 0) {
                maxdt = max(imsidt, maxdt);
                continue;
            }
            if (s[i - 1] > s[i]) {
                imsidt -= regexx[s[i - 1] - 65];
            } else {
                imsidt += regexx[s[i - 1] - 65];
            }
            if (s[i - 1] > to_change) {
                imsidt += regexx[s[i - 1] - 65];
            } else {
                imsidt -= regexx[s[i - 1] - 65];
            }
            if (imsidt == 12098) {
                cout << i << ' ' << j << '\n';
            }
            maxdt = max(imsidt, maxdt);
        } 
        ans = max(ans, maxdt);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}