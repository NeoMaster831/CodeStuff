#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

signed main() {

    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) { int inp; cin >> inp; ans = max(ans, inp - (N - i + 1)); }

    cout << ans << '\n';
}