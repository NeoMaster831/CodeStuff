#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n, k; cin >> n >> k;
    for (int l = k; l <= 100; l++) {
        if (l % 2 == 1 && n % l == 0) {
            int middle = n / l;
            if (middle - l / 2 < 0) continue;
            for (int i = middle - l / 2; i <= middle + l / 2; i++) {
                cout << i << ' ';
            }
            return 0;
        }
        if (l % 2 == 0 && n % l == l / 2) {
            int middle = n / l;
            if (middle - l / 2 + 1 < 0) continue;
            for (int i = middle - l / 2 + 1; i <= middle + l / 2; i++) {
                cout << i << ' ';
            }
            return 0;
        }
    }
    cout << -1 << '\n';
}