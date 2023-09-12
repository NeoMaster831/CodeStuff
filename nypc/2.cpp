#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[200001];

signed main() {


    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> change;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[n]) change.push_back(a[i]);
    }
    if (change.size() == 0) {
        cout << 0; return 0;
    }
    int ans = 0;

    int maxi = -1;
    for (int i = change.size() - 1; i >= 0; i--) {
        if (maxi < change[i]) {
            maxi = change[i];
            ans++;
        }
    }
    cout << ans << '\n';
}