#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    set<double> s;
    for (int i =1; i <= n; i++) {
        int a, b; cin >> a >> b;
        b == 0 ? s.insert(1e9) : s.insert(a / b);
    }

    cout << s.size() << '\n';
}