#include <bits/stdc++.h>

using namespace std;

int N, A[101], B[101];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    } for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] != B[i]) ans++;
    }

    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1);

    int preans = 1;
    for (int i = 1; i <= N; i++) {
        if (A[i] != B[i]) preans++;
    }

    cout << min(ans, preans) << '\n';

}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}