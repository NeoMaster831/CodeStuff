#include <bits/stdc++.h>

using namespace std;
#define int long long

int A[200001], B[200001];

void solve() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    priority_queue<pair<int, int> > pq;
    for (int i = 1; i <= N; i++) {
        int now = A[i] - B[i];
        //cout << now << ' ' << i << '\n';
        pq.push({now, i});
    }

    int maxi = pq.top().first;
    stack<int> ans;

    while (!pq.empty() && pq.top().first >= maxi) {
        ans.push(pq.top().second); pq.pop();
    }
    cout << ans.size() << '\n';
    while (!ans.empty()) { cout << ans.top() << ' '; ans.pop(); }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}