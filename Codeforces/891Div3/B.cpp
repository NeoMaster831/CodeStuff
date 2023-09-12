#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '5') {
            for (int j = i; j < s.size(); j++) s[j] = '0';
            if (i == 0) s = "1" + s;
            else {
                s[i - 1] += 1;
                int j = i - 1;
                while (j >= 0 && s[j] >= '5') {
                    s[j] = '0';
                    if (j == 0) {
                        s = "1" + s;
                    } else s[j - 1] += 1;
                    j--;
                }
            }
            break;
        }
    }
    cout << s << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}