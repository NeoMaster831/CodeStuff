#include <bits/stdc++.h>

using namespace std;

int N, R[10101];

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> R[i];
    }


    int ans = 0;
    for (int i = 1; i <= N; i++) {

        // 1. Must buy 2
        if (R[i + 1] > R[i + 2]) {
            
            int _2s = min(R[i], R[i + 1] - R[i + 2]);

            ans += 5 * _2s;
            R[i] -= _2s; R[i + 1] -= _2s;

            // Buy 3's for left
            int _3s = min({R[i], R[i + 1], R[i + 2]});

            ans += 7 * _3s;
            R[i] -= _3s; R[i + 1] -= _3s; R[i + 2] -= _3s;
        }

        // 2. Else
        else {
            
            int _3s = min({R[i], R[i + 1], R[i + 2]});

            ans += 7 * _3s;
            R[i] -= _3s; R[i + 1] -= _3s; R[i + 2] -= _3s;
            
            int _2s = min(R[i], R[i + 1]);
            ans += 5 * _2s;

            R[i] -= _2s; R[i + 1] -= _2s;
        }
        ans += 3 * R[i];
    }

    cout << ans << '\n';
}