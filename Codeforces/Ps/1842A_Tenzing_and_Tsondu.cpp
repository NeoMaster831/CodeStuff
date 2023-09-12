#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m;

void solve() {
    
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int> > apq, bpq;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp; apq.push(inp);
    }
    for (int i = 1; i <= m; i++) {
        int inp; cin >> inp; bpq.push(inp);
    }

    bool tsondu = true;
    while (!apq.empty() && !bpq.empty()) {
        int atop = apq.top(), btop = bpq.top();
        apq.pop(); bpq.pop();
        int tmp = atop;
        atop -= btop;
        btop -= tmp;
        if (atop <= 0 && btop > 0) bpq.push(btop);
        if (btop <= 0 && atop > 0) apq.push(atop);
    }
    if (apq.empty() && bpq.empty()) cout << "Draw" << '\n';
    else if (apq.empty()) cout << "Tenzing" << '\n';
    else if (bpq.empty()) cout << "Tsondu" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}