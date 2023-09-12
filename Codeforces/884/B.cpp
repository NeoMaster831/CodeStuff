#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;
    deque<int> dq;
    dq.push_back(1);
    bool chare = false;
    for (int i = n; i > 1; i--) {
        if (chare) dq.push_back(i);
        else dq.push_front(i);
        chare = !chare;
    }
    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}
