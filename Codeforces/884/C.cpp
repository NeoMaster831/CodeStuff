#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp; if (i % 2) even.push_back(inp); else odd.push_back(inp);
    }

    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());

    int ans = -987654321234567;
    int sum = 0;
    for (int i = 0; i < odd.size(); i++) {
        sum += odd[i];
        ans = max(ans, sum);
    }
    sum = 0;
    for (int i = 0; i < even.size(); i++) {
        sum += even[i];
        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}