#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m[25001];

void solve() {
    
    cin >> n;
    vector<pair<int, int> > arr;
    int realmini = 98765456712341;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        priority_queue<int, vector<int>, greater<int> > q;
        for (int j = 1; j <= m[i]; j++) {
            int inp; cin >> inp; q.push(inp);
        }
        int mini = q.top(); q.pop();
        realmini = min(realmini, mini);
        int scdmini = q.top();
        arr.push_back({scdmini, mini});
    }
    if (n == 1) {
        cout << arr[0].second << '\n'; return;
    }

    int preans = 0;
    for (int i = 0; i < arr.size(); i++) {
        preans += arr[i].first;
    }
    sort(arr.begin(), arr.end());
    preans -= arr[0].first - realmini;

    cout << preans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}