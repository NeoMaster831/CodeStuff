#include <bits/stdc++.h>

using namespace std;

int dp[3002][101][101][2];
// dp[x][M][m] = 현재 x번째 N 인덱스에 있고, M 중 최댓값을 M번, 최솟값을 m번 씀

int N, M, A[3001], B[101];

//           x         M           m     x - 1을 채택?
int solve(int idx, int h_min, int h_max, bool selected) {

    if (idx >= N + 1 && h_min + h_max >= M) return 0;

    int &cache = dp[idx][h_min][h_max][selected];
    if (cache) return cache;

    // 1. Not putting M
    if (idx <= N) {
        if (!selected) {
            cache = max(cache, solve(idx + 1, h_min, h_max, true) + A[idx]);
        }
        cache = max(cache, solve(idx + 1, h_min, h_max, false));
    }

    // 2. Putting M
    if (h_min + h_max >= M) return cache;
    int h_max_val = B[M - h_max];

    if (!selected) {
        cache = max({cache,
            solve(idx, h_min, h_max + 1, true) + h_max_val,
            solve(idx, h_min + 1, h_max, false)
        });
    } else {
        cache = max(cache, solve(idx, h_min + 1, h_max, false));
    }

    return cache;
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; i++) cin >> B[i];

    sort(B + 1, B + M + 1);

    cout << solve(1, 0, 0, false) << '\n';
}