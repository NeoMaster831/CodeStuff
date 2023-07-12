#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int q, x[200001];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x[i];
    }

    int last = x[1];
    int first = x[1];
    int ptr = 2;

    vector<int> ans;
    ans.push_back(1);
    
    while (ptr <= q) {
        if (x[ptr] < last) break;
        ans.push_back(1);
        last = x[ptr];
        ptr++;
    }
    int prelast = last;
    last = x[ptr];
    ans.push_back(1);
    ptr++;
    while (ptr <= q) {
        if (x[ptr] < last || (x[ptr] > first && x[ptr] < prelast)) {
            ans.push_back(0);
            ptr++;
            continue;
        }
        ans.push_back(1);
        last = x[ptr];
        ptr++;
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}