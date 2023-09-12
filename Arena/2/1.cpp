#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N; cin >> N;
    int sum = 0;
    int sum3 = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
        sum3 += i * i * i;
    }
    cout << sum << '\n' << sum * sum << '\n' << sum3 << '\n';
    
}