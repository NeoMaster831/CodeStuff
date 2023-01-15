#include <bits/stdc++.h>

using namespace std;
#define int long long

bool lid[200001];
int N, A[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%1d", &lid[i]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    int start = 1;
    for (int i = 1; i <= N; i++) {
        if (!lid[i]) break;
        start++; ans += A[i];
    }

    for (int i = start; i <= N; i++) {
        pq.push(A[i]);
        if (!lid[i + 1]) {
            pq.pop();
            while (!pq.empty()) {
                ans += pq.top(); pq.pop();
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
}