#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;

signed main() {

    cin >> N >> M;

    pair<int, int> minN = { 9876543212345678, -1 };
    pair<int, int> minM = { 9876543212345678, -1 };
    for (int i = 1; i <= N - 1; i++) {
        
        int inp; cin >> inp;
        if (minN.first > inp) {
            minN = { inp, i };
        }
    }
    int inp; cin >> inp;
    if (minN.first > inp) minN = {inp, N};
    if (minM.first > inp) minM = {inp, 1};
    for (int i = 2; i <= M; i++) {
        int inp; cin >> inp;
        if (minM.first > inp) {
            minM = { inp, i};
        }
    }

    cout << minN.second << ' ' << minM.second << '\n';
}