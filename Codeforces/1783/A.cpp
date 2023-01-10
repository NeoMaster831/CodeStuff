#include <bits/stdc++.h>

using namespace std;

int N, A[51];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + 1 + N);

    vector<int> ans; ans.push_back(A[N]);
    for (int i = N - 1; i >= 1; i--) {
         if (i == N - 1 && A[N] == A[N - 1]) {
            
            bool cant = true;
            for (int j = i - 1; j >= 1; j--) {
                if (A[j] != A[i]) {
                    int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
                    cant = false;
                }
            }
            if (cant) { cout << "NO" << '\n'; return; }
        }
        ans.push_back(A[i]);
    }

    cout << "YES" << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}