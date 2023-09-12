#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[101][38], C[101];
signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        for (int j = 1; j <= C[i]; j++) {
            cin >> A[i][j];
        }
    }

    int X; cin >> X;
    int mini = 9876543456;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= C[i]; j++) {
            if (A[i][j] == X) {
                mini = min(mini, C[i]); break;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= C[i]; j++) {
            if (A[i][j] == X && C[i] == mini) {
                ans.push_back(i); break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
}