#include <bits/stdc++.h>

using namespace std;
#define pp pair<int, int>

int N, M;
int ans[401][401];

bool isJegob(int num) {
    if (sqrt(num) - (int)sqrt(num) == 0) return true;
    else return false;
}

int main() {

    cin >> N >> M;
    memset(ans, -1, sizeof(ans));

    pp start = { 1, 1 };
    queue<pair<pp, int> > q; q.push({ start, 0} );

    while (!q.empty()) {

        pair<pp, int> fr = q.front(); q.pop();
        int x = fr.first.first, y = fr.first.second;
        int depth = fr.second;

        if (x > N || x <= 0 || y > N || y <= 0) continue;
        if (ans[x][y] != -1) continue;
        ans[x][y] = depth;

        for (int i = 1; i * i <= M; i++) {
            
            int iJegob = i * i;
            int jJegob = M - iJegob;
            if (!isJegob(jJegob)) continue;
            int j = (int)sqrt(jJegob);

            // 8 case, x의 증가량, y의 증가량
            int d[8][2] = { {i, j} , {j, i}, {-i, j}, {-j, i},
            {-i, -j}, {-j, -i}, {i, -j}, {j, -i} };

            for (int k = 0; k < 8; k++) {
                q.push({{d[k][0] + x, d[k][1] + y}, depth + 1});
            }

        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}