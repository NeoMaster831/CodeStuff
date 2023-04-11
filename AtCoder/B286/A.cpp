#include <bits/stdc++.h>

using namespace std;
#define int long long

int A[100001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        A[inp] = 1;
    }
}