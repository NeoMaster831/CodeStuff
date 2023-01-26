#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 2354723985648

int N, M, A[100001];
bool chk[100001];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int checker = M / 2 + 1;
    sort(A + 1, A + N + 1);

    int l = 1, r = 1, cnt = 0;
    int ans = INF;
    while (r <= N) {

        int remain = A[r] % M;
        if (remain == 0) remain = M;

        if (remain < checker) {
            r++;
            continue;
        }
        else {
            
            int re = remain % M;
            if (chk[remain] == true && A[l] % M == re) {
                while (A[l] % M == re || A[l] % M < checker) {
                    l++;
                }
            }
            if (chk[remain] == false) {
                cnt++; chk[remain] = true;
            }

            if (cnt >= (M / 2) + (M % 2)) {
                ans = min(ans, A[r] - A[l]);
            }

        }
        
        r++;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}