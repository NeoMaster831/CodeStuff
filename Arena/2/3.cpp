#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    int maxi = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        maxi = max(maxi, A[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] == maxi) continue;
        int mini = abs(maxi - A[i]);
        //cout << mini << ' ' <<maxi - A[i] * 2 << '\n';
        while (true) {
            if (mini <= abs(maxi - A[i] * 2) || maxi - A[i] * 2 < 0) break;
            A[i] *= 2;
            mini = abs(maxi - A[i]);
        }
    }

    int maxii = 0, minii = 9876543234567;
    for (int i =1; i <= N; i++) {
        //cout << A[i] << ' ';
        maxii = max(maxii, A[i]);
        minii = min(minii, A[i]);
    }

    cout << maxii - minii << '\n';
}