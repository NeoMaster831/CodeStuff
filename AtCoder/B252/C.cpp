#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
string S[101];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    int ans = 99999999;
    for (int k = 0; k <= 9; k++) {
        
        int jb[11]; for (int i = 1; i <= 10; i++) {
            jb[i] = 0;
        }
        
        int mini = 99, maxi = -1;
        for (int i = 1; i <= N; i++) {
            
            int loc;
            for (int j = 0; j < S[i].size(); j++) {
                if (S[i][j] == k + 48) loc = j + 1;
            }

            jb[loc]++;
            mini = min(loc, mini);
            maxi = max(loc, maxi);
        }
        
        int jbmax = 0;
        for (int i = 1; i <= 10; i++) {
            jbmax = max(jb[i] - 1, jbmax);
        }

        if (jbmax == 0) ans = min(maxi, ans);
        else ans = min(jbmax * 10 + mini, ans);
    }

    cout << ans - 1 << '\n';
}