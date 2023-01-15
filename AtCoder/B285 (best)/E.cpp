#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[5001], dp[10001], psum[5001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    psum[0] = 0;
    psum[1] = A[1];
    for (int i = 2; i <= N; i++) psum[i] = A[i] + psum[i - 1];

    dp[1] = 0;
    for (int i = 2; i <= N + 1; i++) {
        for (int j = 1; i - j >= 1; j++) {

            int oldis = j / 2;

            int x = psum[oldis] * 2; // Base case
            if (j % 2 == 0) {
                x -= A[oldis];
            }

            //cout << "i: " << i << ", j: " << j << ", x: " << x << '\n';
            dp[i] = max(dp[i], x + dp[i - j]);
        }

    }

    cout << max(dp[N], dp[N + 1]) << '\n';
}