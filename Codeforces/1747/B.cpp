#include <bits/stdc++.h>

using namespace std;

int N;

void solve() {
    
    cin >> N;
    int cutlane = (3 * N) / 2 + 1;
    if (N % 2 == 1) cutlane++;

    vector<int> to;
    for (int i = 1; i < cutlane; i++) {
        if (i % 3 == 2) to.push_back(i);
    }

    vector<int> from;
    for (int i = cutlane; i <= N * 3; i++) {
        if (i % 3 == 0) from.push_back(i);
    }

    cout << from.size() << '\n';
    for (int i = 0; i < from.size(); i++) {
        cout << from[i] << ' ' << to[i] << '\n';
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}