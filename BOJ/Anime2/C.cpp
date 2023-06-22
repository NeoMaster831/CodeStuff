#include <bits/stdc++.h>

using namespace std;
#define int long long

bool shiganpyo[1000001];

signed main() {
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        shiganpyo[inp] = 1;
    }

    priority_queue<int> pq;
    int in_queue = 0;
    for (int i = 1000000; i >= 0; i--) {
        if (shiganpyo[i] == 1) {
            pq.push(i);
            continue;
        }
        if (shiganpyo[i] == 0) {
            if (pq.empty()) {
                in_queue = max(0LL, in_queue - 1);
            } else {
                int t = pq.top();
                pq.pop();
                if (t - M > i) {
                    cout << "fail" << '\n';
                    return 0;
                }
                in_queue++;
            }
        }
    }
    if (in_queue || !pq.empty() ) cout << "fail" << '\n';
    else cout << "success" << '\n';
}