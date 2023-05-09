#include <iostream>
#include <algorithm>

using namespace std;
#define int long long
#define INF 987654312345678

int N, K, M[100001];

int solve() {

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> M[i];

    // (N + K)log(M)
    int l = 1, r = INF;
    int ans = 2 * INF;
    while (l <= r) {
        int m = (l + r) / 2; // 간격
        
        int demand = 0;
        for (int i = 1; i < N; i++) {
            demand += (M[i + 1] - M[i]) / m - ((M[i + 1] - M[i]) % m == 0);
        }

        if (demand > K) {
            l = m + 1;
        }
        else {
            ans = min(ans, m);
            r = m - 1;
        }
    }
    return ans;
}

signed main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int r = solve();
        cout << "Case #" << i << ": " << r << '\n';
    }
}