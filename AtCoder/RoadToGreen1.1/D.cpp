#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007

int N, A[100001], cnt[100001];

int YeeJegob(int x) {
    int ans = 1;
    for (int i = 1; i <= x; i++) {
        ans = (ans % MOD) * (2 % MOD) % MOD;
    }
    return ans;
}

signed main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i]; cnt[A[i]]++;
    }

    if (N % 2 == 0) {
        for (int i = 1; i <= N - 1; i += 2) {
            if (cnt[i] != 2) { cout << 0 << '\n'; return 0; }
        }
    } else {
        for (int i = 0; i <= N - 1; i += 2) {
            if (i == 0) {
                if (cnt[i] != 1) { cout << 0 << '\n'; return 0; }
            } else {
                if (cnt[i] != 2) { cout << 0 << '\n'; return 0; }
            }
        }
    }

    cout << YeeJegob(N / 2) << '\n';
}