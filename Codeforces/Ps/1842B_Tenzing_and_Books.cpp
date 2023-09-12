#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, x, arr[4][100001];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];

    int ptr[4] = { -100, 1, 1, 1 }, l = n;
    int kn = 0;
    for (int i = 1; i <= 3; i++) {

        for (int j = 1; j <= n; j++) {
            if (kn == x) {cout <<"yes" << '\n'; return;}
            vector<int> bits;
            int arrij = arr[i][j];
            while (arrij) {
                bits.push_back(arrij % 2);
                arrij /= 2;
            }

            bool invalid = false;
            for (int k = 0; k < bits.size(); k++) {
                if (bits[k] == 1 && (x & (1 << k)) == 0) {
                    invalid = true;
                    break;
                }
            }
            if (invalid) break;
            kn |= arr[i][j];

        }
    }
    if (kn == x) cout << "yes" << '\n';
    else cout << "no" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}