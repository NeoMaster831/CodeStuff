#include <iostream>
#include <memory.h>

using namespace std;
#define int long long
#define INF 9876543212345678

int pv[51][31], knapsack[51][12345]; // i번째에서 j개 썼을 때 최댓값
int N, K, P;

int fill_dp(int where, int plates) {

    if (where > N) {
        //cout << plates << '\n';
        if (plates == P) return 0;
        else return -INF;
    }
    int& cache = knapsack[where][plates];
    if (cache != -1) return cache;
    cache = 0;
    for (int i = 0; i <= K; i++) { // i = 이번 턴에서 구매할 개수
        if (i + plates > P) continue;
        int preans = fill_dp(where + 1, i + plates);
        //cout << where << ' ' << i << ' ' << preans << '\n';
        for (int j = 1; j <= i; j++) {
            preans += pv[where][j];
        }
        cache = max(cache, preans);
    }

    return cache;
}

int solve() {

    cin >> N >> K >> P;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= K; j++)
            cin >> pv[i][j];
    memset(knapsack, -1, sizeof(knapsack));

    int ans = fill_dp(1, 0);
    return ans;
}

signed main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int r = solve();
        cout << "Case #" << i << ": " << r << '\n';
    }
}