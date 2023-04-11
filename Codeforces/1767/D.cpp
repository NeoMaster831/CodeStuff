#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
string S;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> S;

    int competors = (1 << N);
    for (int i = 1; i <= competors; i++) {
        
        int l = i - 1, r = competors - i;
        bool winning = true;
        for (int j = 0; j < S.size(); j++) {

            if (i == 8) cout << "i: " << i << ", l: " << l << ", r: " << r << ", S[j] = " << S[j] << '\n';
            if ((l <= 0 && S[j] == '1') || (r <= 0 && S[j] == '0')) {
                winning = false;
                break;
            }
            if (S[j] == '0' && r % 2 == 0) {
                r = r / 2 - 1; l = l / 2 + 1;
            } else if (S[j] == '0' && r % 2 == 1) {
                r = r / 2; l = l / 2;
            } else if (S[j] == '1' && l % 2 == 0) {
                l = l / 2 - 1; r = r / 2 + 1;
            } else if (S[j] == '1' && l % 2 == 1) {
                l = l / 2; r = r / 2;
            }
        }

        if (winning) cout << i << ' ';
    }
    cout << '\n';
}