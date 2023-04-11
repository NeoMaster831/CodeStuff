#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000

int H, W, dp[1001][2];
int A[1002][1002];

int main() {

    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> A[i][j];
    for (int i = 1; i <= H; i++) {
        A[i][0] = 2; A[i][W + 1] = 2;
    } for (int i = 1; i <= W; i++) {
        A[0][i] = 2; A[H + 1][i] = 2;
    }

    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            cout << A[i][j] << ' ';
        }

        cout << '\n';
    }
}