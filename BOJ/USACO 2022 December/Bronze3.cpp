#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
#define int long long

int N, M, res[101];
bool chk[101];

bool solve() {
    string b[101];
    memset(res, 0, sizeof(res));
    memset(chk, false, sizeof(chk));
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> b[i] >> res[i];
    }
    
    bool can = true;
    while (can) {
        
        for (int i = 1; i <= M; i++) {
            //cout << chk[i] << ' ';
        }
        //cout << '\n';
        for (int k = 0; k < 2; k++) {
            bool looptalchul = true;
            for (int j = 1; j <= M; j++) {
                if (chk[j]) continue;
                if (res[j] != k) { looptalchul = false; break; }
            }
            if (looptalchul) return true;
        }

        bool ok = false;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < 4; k++) {

                bool yes = true; int cnt = 0;
                for (int j = 1; j <= M; j++) {
                    if (chk[j]) continue;
                    if (b[j][i] - 48 != k / 2) continue;
                    cnt++;
                    if (b[j][i] - 48 != res[j] ^ (k % 2)) { yes = false; break; }
                }
                if (!cnt) yes = false;
                if (yes) {
                    for (int j = 1; j <= M; j++) {
                        if (chk[j]) continue;
                        if (b[j][i] - 48 != k / 2) continue;
                        if (b[j][i] - 48 == res[j] ^ (k % 2)) chk[j] = true;
                    }
                    ok = true; break;
                }
            }
        }

        if (ok) continue;
        return false;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while (T--) {
        bool res = solve();
        if (res) cout << "OK" << '\n';
        else cout << "LIE" << '\n';
    }
}