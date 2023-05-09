#include <iostream>
#include <algorithm>

using namespace std;
#define int long long

int N, B, A[100001];

int solve() {
    cin >> N >> B;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (B < A[i]) break;
        ans++; B -= A[i];
    }

    return ans;
}

signed main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int r = solve();
        cout << "Case #" << i << ": " << r << '\n';
    }
}