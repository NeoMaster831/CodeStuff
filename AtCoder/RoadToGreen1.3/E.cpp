#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 987654321234567

int N, F[101][11], P[101][11];

int solve(int bitmask) {
    int profit = 0;
    for (int k = 1; k <= N; k++) { // Shop i번째가 l 구간에서 몇 개 켜져있는지 체크

        int precnt = 0;
        for (int l = 1; l <= 10; l++) {
            int kthbit = l - 1;
            if (F[k][l] == 1 && (bitmask & (1 << kthbit))) {
               precnt++;
            }
        }
        profit += P[k][precnt];
    }
    return profit;
}

signed main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> F[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10; j++) {
            cin >> P[i][j];
        }
    }
    int ans = -INF;
    for (int i = 1; i < 1024; i++) {
        int p = solve(i);
        ans = max(ans, p);
    }

    cout << ans << '\n';
}