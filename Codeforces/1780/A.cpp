#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[301];

void solve() {

    cin >> N;

    int odds = 0, evens = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 1) odds++;
        else evens++;
    }

    if (odds >= 3) {
        
        cout << "YES" << '\n';
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            
            if (cnt == 3) break;
            if (A[i] % 2 == 1) {
                cnt++; cout << i << ' ';
            }
        }
        cout << '\n';

    } else if (odds >= 1 && evens >= 2) {
        
        cout << "YES" << '\n';
        int oddcnt = 0, evencnt = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] % 2 == 1 && oddcnt < 1) {
                oddcnt++;
                cout << i << ' ';
            }
            if (A[i] % 2 == 0 && evencnt < 2) {
                evencnt++;
                cout << i << ' ';
            }
        }

        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}