#include <bits/stdc++.h>

using namespace std;

int N, Q, A[100001];

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    cin >> Q;
    while (Q--) {
        int q; cin >> q;
        if (q == 1) {
            int k, x; cin >> k >> x;
            A[k] = x;
        } else {

            int k; cin >> k;
            cout << A[k] << '\n';
        }
    }
}