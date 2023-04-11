#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, S, R, maxi;

void solve() {
    
    cin >> N >> S >> R;
    maxi = S - R;

    int left = N;
    while (S - maxi >= left) {
        S -= maxi;
        cout << maxi << ' ';
        left--;
    }
    while (left != 1) {
        S -= 1;
        cout << 1 << ' ';
        left--;
    }

    cout << S << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}