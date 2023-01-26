#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, K, Q, A[203]; // NOT INDEX!!

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> Q;
    for (int i = 1; i <= K; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= Q; i++) {
        int L; cin >> L;
        if (A[L] != N && A[L] + 1 != A[L + 1]) {
            A[L]++;
        }
    }

    for (int i = 1; i <= K; i++) {
        cout << A[i] << ' ';
    }

    cout << '\n';
}