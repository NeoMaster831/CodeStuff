#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, start[2], endp[2], parent[3001], s, e;
int Circle[3001][3];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x); y = Find(y);
    if (x != y) parent[x] = y;
}

int getdist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

signed main() {
    
    cin >> N;
    cin >> start[0] >> start[1] >> endp[0] >> endp[1];
    for (int i = 1; i <= N; i++) {
        cin >> Circle[i][0] >> Circle[i][1] >> Circle[i][2];
    }

    for (int i = 1; i <= N; i++) {
        int x = Circle[i][0];
        int y = Circle[i][1];
        int r = Circle[i][2];

        if (getdist(x, y, start[0], start[1]) == r * r) {
            s = i;
        }
        if (getdist(x, y, endp[0], endp[1]) == r * r) {
            e = i;
        }
    }

    if (s == 0 || e == 0) {
        cout << "No" << '\n'; return 0;
    }

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            
            int x = Circle[i][0], y = Circle[i][1], r = Circle[i][2];
            int xp = Circle[j][0], yp = Circle[j][1], rp = Circle[j][2];

            int dist = getdist(x, y, xp, yp);
            int rPlusJegob = (r + rp) * (r + rp);
            int rMinusJegob = (r - rp) * (r - rp);

            if (dist <= rPlusJegob && dist >= rMinusJegob) {
                Union(i, j);
            }

        }
    }

    if (Find(s) == Find(e)) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}