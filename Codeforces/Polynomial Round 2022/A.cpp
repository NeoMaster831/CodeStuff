#include <bits/stdc++.h>

using namespace std;
#define int long long

// ignore 0's
// just think of 1's

int N;
string S;

void solve() {

    cin >> N >> S;
    bool flag = true;
    for (int i = 1; i < N; i++) {
        if (S[i] == '0') {
            cout << "+";
        } else {
            if (flag) cout << "-";
            else cout << "+";
            flag = !flag;
        }
    }

    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}