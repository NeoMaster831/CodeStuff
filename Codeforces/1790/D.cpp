#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1);

    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(A[1]); int ans = 0;
    for (int i = 2; i <= N; i++) {

        int t = pq.top();
        if (A[i] > t && A[i] - 1 != t) {
            while (!pq.empty()) {
                if (pq.top() == A[i] - 1) break;
                pq.pop();
                ans++;
            }
            if (pq.empty()) {
                pq.push(A[i]); continue;
            }
            t = pq.top();
        }
        if (A[i] - 1 == t) {
            pq.pop(); pq.push(A[i]);
        } else if (A[i] == t) {
            pq.push(A[i]);
        }
    }

    //if (N == 8) cout << "DEBUG: " << ans << ", " << pq.size() << '\n';
    while (!pq.empty()) {
        pq.pop(); ans++;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}