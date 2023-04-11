#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= N; i++) {
        if (A[i] > A[1]) pq.push(A[i]);
    }

    while (!pq.empty()) {
        int t = pq.top(); pq.pop();
        if (t <= A[1]) continue;
        int sub = t - A[1];
        A[1] += (sub / 2) + (sub % 2);
    }

    cout << A[1] << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}