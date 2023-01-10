#include <bits/stdc++.h>

using namespace std;

int N, A[513];
bool canswap[11];

void solve() {

    cin >> N;
    for (int i = 1; i<= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int val = A[i] ^ A[j];

            for (int k = 0; k < 10; k++) {
                if (val & (1 << k)) canswap[k] = true;
            }
        }
    }

    int maxi = 0;
    int mini = 0;
    for (int k = 0; k < 10; k++) {
        maxi += (1 << k) * canswap[k];
        if (!canswap[k]) {
            mini += (A[1] & (1 << k));
        }
    }

    cout << maxi - mini << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}