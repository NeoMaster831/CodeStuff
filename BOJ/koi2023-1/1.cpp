#include <bits/stdc++.h>

using namespace std;
#define int long long

struct point {
    int x, y;
};

signed main() {
    int N, K; cin >> N >> K;
    point house[51];
    for (int i = 1; i <= N; i++) {
        cin >> house[i].x >> house[i].y;
    }

    int mini = 98765434567654345;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                int maxi = 0;
                for (int p = 1; p <= N; p++) {
                    int goi = K >= 1 ? abs(house[p].x - house[i].x) + abs(house[p].y - house[i].y) : 1234567898765432;
                    int goj = K >= 2 ? abs(house[p].x - house[j].x) + abs(house[p].y - house[j].y) : 123456789876543;
                    int gok = K >= 3 ? abs(house[p].x - house[k].x) + abs(house[p].y - house[k].y) : 12345678987654;
                    maxi = max(maxi, min(goi, min(goj, gok)));
                }
                mini = min(mini, maxi);
            }
        }
    }

    cout << mini << '\n';
}