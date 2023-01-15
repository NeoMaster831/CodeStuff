#include <bits/stdc++.h>

using namespace std;
#define int long long

string S;
int _26Jinsu[17];

signed main() {

    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        _26Jinsu[i + 1] = S[i] - 65 + 1;
    }

    int pow26 = 1, ans = 0;
    for (int i = S.size(); i >= 1; i--) {
        ans += _26Jinsu[i] * pow26;
        pow26 *= 26;
    }

    cout << ans << '\n';
}