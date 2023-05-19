#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;

signed main() {

    cin >> N >> M;
    int demand = (M / N) + (M % N != 0);
    int ans = (M / demand) + (M % demand != 0);

    if (demand > N || ans > N) cout << -1 << '\n';
    else cout << ans * demand << '\n';
    
}