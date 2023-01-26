#include <bits/stdc++.h>

using namespace std;
#define int long long

int A, B;

void solve() {

    cin >> A >> B;
    cout << min(2LL, A) << ' ' << min(2LL, B) << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}