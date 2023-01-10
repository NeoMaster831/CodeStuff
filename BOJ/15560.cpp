#include <bits/stdc++.h>

using namespace std;

int N, Q, U, V;
int K[1001], dp[1001][1001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q >> U >> V;
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
        K[i] *= U;
    }


    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int from, to; cin >> from >> to;

            dp[Q][from] = K[from];
            for (int i = from + 1; i <= to; i++) {
                if (dp[Q][i - 1] + V < 0) dp[Q][i] = K[i];
                else dp[Q][i] = dp[Q][i - 1] + V + K[i];
            }
            
            int ans = -999999999;
            for (int i = from; i <= to; i++) {
                ans = max(dp[Q][i], ans);
            }

            cout << ans << '\n';

        } else {
            int what, val; cin >> what >> val;
            K[what] = val * U;
        }
    }
}