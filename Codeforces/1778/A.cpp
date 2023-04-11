#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[100001];

void solve() {

    cin >> N;
    int axis = 0, sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
        if (A[i] == -1 && A[i] == A[i - 1]) {
            axis = 4;
        }
    }

    if (axis == 0) {

        bool end = false;
        for (int i = 2; i <= N; i++) {
            if (A[i] != A[i - 1]) end = true;
        }

        if (end == false) axis = -4;
    }

    cout << sum + axis << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}