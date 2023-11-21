#include <iostream>

using namespace std;
#define int long long

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (n < k || k > x + 1) {
        cout << -1 << '\n'; return;
    }
    int s = 0;
    for (int i = 0; i <= k - 1; i++) {
        s += i;
    }
    for (int i = 0; i < n - k; i++) {
        s += (x == k ? x - 1 : x);
    }
    cout << s << '\n';
}

signed main() {
    int T; cin >> T; while (T--) solve();
}