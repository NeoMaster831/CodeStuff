#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pp pair<int, int>

int N, A[100001];

void solve() {
    
    cin >> N;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        max_pq.push(A[i]); min_pq.push(A[i]);
    }

    int f = max_pq.top(); max_pq.pop(); int s = max_pq.top();
    int t = min_pq.top(); min_pq.pop(); int four = min_pq.top();

    cout << f + s - t - four << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}