#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200010];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);

    A[0] = -1, A[N + 1] = 12837482136478;
    int ans = 0;
    for (int i = 0; i <= N; i++) { // ~i 까지 포함했을 때 되는가?
        // 1. 일단 이게 되는가?
        //cout << "i: " << i;
        if (A[i] >= i) {
            //cout << ", Cant cuz " << A[i] << " >= " << i << '\n';
            continue;
        }
        // 2. 추후에 Collision이 일어나는가?
        if (A[i + 1] <= i) {
            //cout << ", Cant cuz " << A[i + 1] << " <= " << i << '\n';
            continue;
        }
        //cout << '\n';

        ans++;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}