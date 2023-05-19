#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ppi pair<pair<int, int>, int>

int K, N;
ppi Probe[1001];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> K >> N;
    for (int i = 1; i <= N; i++) {
        int x, y, r; cin >> x >> y >> r;
        Probe[i] = { {x, y}, r };
    }

    
}