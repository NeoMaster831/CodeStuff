#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 998244353

signed main() {

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int g = (a % MOD) * (b % MOD) % MOD;
    int h = (g % MOD) * (c % MOD) % MOD;
    int i = (d % MOD) * (e % MOD) % MOD;
    int j = (i % MOD) * (f % MOD) % MOD;

    cout << (h + MOD - j) % MOD << '\n';
    
}