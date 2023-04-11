#include <bits/stdc++.h>

using namespace std;
#define int long long

// Trivial Informations
// 1. if the player has { w, i, n }, you dont have to make exchanges with others.
// 1-1. if the player has the letter only one, you dont have to make exchanges with that letter.
// 2. Exchange -> 2 with 3

int M;

void solve() {
    
    set<int> d[4][4][4];
    vector<int> A;

    cin >> M;
    for (int i = 1; i <= M; i++) {
        string inp; cin >> inp;
        int wc = 0, ic = 0, nc = 0;
        for (int j = 0; j < inp.size(); j++) {
            if (inp[j] == 'w') wc++;
            else if (inp[j] == 'i') ic++;
            else nc++;
        }

        A.push_back(i);
        d[wc][ic][nc].insert(i);
    }

    vector<pair<pair<int, char>, pair<int, char> > > ans;
    for (int i = 0; i < A.size(); i++) {
        
        int index = A[i];
        int wc, ic, nc;

        for (int a = 0; a <= 3; a++) {
            for (int b = 0; b <= 3; b++) {
                for (int c = 0; c <= 3; c++) {
                    if (d[a][b][c].find(index) != d[a][b][c].end()) {
                        d[a][b][c].erase(index);
                        wc = a; ic = b; nc = c;
                        break;
                    }
                }
            }
        }
        cout << "Index: " << index << ", " << wc << ", " << ic << ", " << nc << '\n';

        while (wc != 1 || ic != 1 || nc != 1) {

            if (wc >= 2) {
                if (ic != 1) {
                    int target_idx;
                    if (d[0][3][0].empty()) {
                        if (d[0][2][1].empty()) {
                            target_idx = *d[1][0][2].begin();
                            d[1][0][2].erase(target_idx);
                            d[2][0][1].insert(target_idx);
                        }
                        else {
                            target_idx = *d[0][2][1].begin();
                            d[0][2][1].erase(target_idx);
                            d[1][1][1].insert(target_idx);
                        }
                    } else {
                        target_idx = *d[0][3][0].begin();
                        d[0][3][0].erase(target_idx);
                        d[1][2][0].insert(target_idx);
                    }
                    ic++; wc--;
                    ans.push_back({{index, 'w'}, {target_idx, 'i'}});
                    continue;
                }
                if (nc != 1) {
                    int target_idx;
                    if (d[0][0][3].empty()) {
                        if (d[0][1][2].empty()) {
                            target_idx = *d[1][0][2].begin();
                            d[1][0][2].erase(target_idx);
                            d[2][0][1].insert(target_idx);
                        }
                        else {
                            target_idx = *d[0][1][2].begin();
                            d[0][1][2].erase(target_idx);
                            d[1][1][1].insert(target_idx);
                        }
                    } else {
                        target_idx = *d[0][0][3].begin();
                        d[0][0][3].erase(target_idx);
                        d[1][0][2].insert(target_idx);
                    }
                    nc++; wc--;
                    ans.push_back({{index, 'w'}, {target_idx, 'n'}});
                    continue;
                }
            }
            else if (ic >= 2) {
                // i를 주고 w를 받기
                if (wc != 1) {
                    int target_idx;
                    if (d[3][0][0].empty()) {
                        target_idx = *d[2][0][1].begin();
                        d[2][0][1].erase(target_idx);
                        d[1][1][1].insert(target_idx);
                    } else {
                        target_idx = *d[3][0][0].begin();
                        d[3][0][0].erase(target_idx);
                        d[2][1][0].insert(target_idx);
                    }
                    wc++; ic--;
                    ans.push_back({{index, 'i'}, {target_idx, 'w'}});
                    continue;
                }
                if (nc != 1) {
                    int target_idx;
                    if (d[0][0][3].empty()) {
                        target_idx = *d[1][0][2].begin();
                        d[1][0][2].erase(target_idx);
                        d[1][1][1].insert(target_idx);
                    } else {
                        target_idx = *d[0][0][3].begin();
                        d[0][0][3].erase(target_idx);
                        d[0][1][2].insert(target_idx);
                    }
                    nc++; ic--;
                    ans.push_back({{index, 'i'}, {target_idx, 'n'}});
                    continue;
                }
            }
            else if (nc >= 2) {
                if (wc != 1) {
                    int target_idx;
                    if (d[3][0][0].empty()) {
                        cout << "WOW" << ' ';
                        target_idx = *d[2][0][1].begin();
                        d[2][1][0].erase(target_idx);
                        d[1][1][1].insert(target_idx);
                    } else {
                        target_idx = *d[3][0][0].begin();
                        d[3][0][0].erase(target_idx);
                        d[2][0][1].insert(target_idx);
                    }
                    wc++; nc--;
                    ans.push_back({{index, 'n'}, {target_idx, 'w'}});
                    continue;
                }
                if (ic != 1) {
                    int target_idx;
                    if (d[0][3][0].empty()) {
                        target_idx = *d[1][2][0].begin();
                        d[1][2][0].erase(target_idx);
                        d[1][1][1].insert(target_idx);
                    } else {
                        target_idx = *d[0][3][0].begin();
                        d[0][3][0].erase(target_idx);
                        d[0][2][1].insert(target_idx);
                    }
                    ic++; nc--;
                    ans.push_back({{index, 'n'}, {target_idx, 'i'}});
                    continue;
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout <<
        ans[i].first.first << ' ' <<
        ans[i].first.second << ' ' <<
        ans[i].second.first << ' ' << 
        ans[i].second.second << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}