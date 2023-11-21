#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[100001];
int b[32];

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= 31; i++) {
        b[i] = 9876789;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } for (int i = 1; i <= q; i++) {
        int inp; cin >> inp; b[inp] = min(b[inp], i);
    }
    // 1 0000000 일 때 11111111 로 만듬.
    // 1 0 1 0 0 0 0 for each bits, search for last 
    vector<int> anigger;
    anigger.push_back(0);
    for (int i = 1; i <= n; i++) {
        
        int bit = 0; // 1
        //cout << "S: " << (a[i] & (1 << bit)) << '\n';
        while ((a[i] & (1 << bit)) == 0) {
            //cout << a[i] << ' ' << (1 << bit) << ' ' << bit << '\n';
            bit++;
        }

        pair<int, int> mini = { 99999, 6974 }; // idx, bit
        for (int j = 1; j <= bit; j++) {
            //cout << i << ": " << b[j] << ' ' << j << '\n';
            if (b[j] < mini.first) {
                mini = {b[j], j};
                a[i] += (1 << (mini.second - 1));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}