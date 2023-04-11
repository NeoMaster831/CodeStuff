#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[102][102];

void solve() {

    for (int i = 0; i <= 101; i++) {
        for (int j = 0; j <= 101; j++) A[i][j] = 0;
    }

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - 1; j++) {
            cin >> A[i][j];
        }
    }

    int l = 1, r = 1;
    while (l != N || r != N) {
        if (A[1][l] != A[2][r]) {
            
            if (A[1][l + 1] == A[2][r + 1]) {
                for (int i = 1; i <= N - 1; i++) {
                    if (A[3][i] == A[1][l]) { 
                        cout << A[1][l] << ' ';
                        if (A[2][r] != 0) cout << A[2][r] << ' ';
                        break; }
                    else if (A[3][i] == A[2][r]) { 
                        cout << A[2][r] << ' ';
                        if (A[1][l] != 0) cout << A[1][l] << ' ';
                        break; }
                }
                l++; r++;
            } else if (A[1][l + 1] == A[2][r]) {
                cout << A[1][l] << ' ';
                l++;
            } else if (A[2][r + 1] == A[1][l]) {
                cout << A[2][r] << ' ';
                r++;
            }
        }

        if (l >= N || r >= N) break;

        cout << A[1][l] << ' ';
        l++; r++;
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}