#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, X, nb[100], xb[100];

void toBinary(int n, int depth, bool mode)
{
    if (n / 2 != 0) {
        toBinary(n / 2, depth + 1, mode);
    }
 
    if (mode) xb[depth] = n % 2;
    else nb[depth] = n % 2;
}

void solve() {
    
    for (int i = 0; i < 100; i++) nb[i] = 0;

    cin >> N >> X;
    toBinary(N, 0, 0); toBinary(X, 0, 1);

    int szN = (int)(log2(N)) + 1;
    int szX = (int)(log2(X)) + 1;

    int ans = N;
    for (int i = 0; i < max(szN, szX + 2); i++) {
        if (nb[i] == 1 && xb[i] == 0) {
            int sum = (1 << i);
            for (int j = i; j >= 0; j--) {
                if (nb[j] == 1) {
                    nb[j] = 0;
                    sum -= (1 << (j - 1));
                }
            }
            cout << sum << '\n';
            ans += sum;
            int j = i;
            while (nb[j] != 0) {
                nb[j] = 0; j++;
            }

        }
        else if (nb[i] == 0 && xb[i] == 1) {
            cout << -1 << '\n'; return;
        }
        else if (nb[i] == 1 && xb[i] == 1) {
            for (int j = i + 1; j < szX; j++) {
                if (nb[j] != xb[j]) {
                    cout << -1 << '\n'; return;
                }
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}