#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

void solve() {
    
    cin >> N;
    int nSum = 0, pSum = 0;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        if (inp > 0) pSum += inp;
        else nSum -= inp;
    }

    cout << abs(max(nSum, pSum)) - abs(min(nSum, pSum)) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}