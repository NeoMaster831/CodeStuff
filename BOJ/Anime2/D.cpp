#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M, F;
char Map[81][81];

signed main() {

    cin >> N >> M >> F;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            Map[i][j] = s[j - 1];
        }
    }

    // 둘레 구하기
    int sum = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int g = (Map[i][j] == '#') + (Map[i - 1][j] == '#');
            if (g == 1) sum++;
        }
    }
    for (int j = 2; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            int g = (Map[i][j] == '#') + (Map[i][j - 1] == '#');
            if (g == 1) sum++;
        }
    }

    for (int i = 2; i <= N; i++) {
        
        int j;
        int leeduk = -F;
        for (j = 1; j <= M && !(Map[i][j] == '#' && Map[i - 1][j] == '#'); j++) {
            int g = (Map[i][j] == '#') + (Map[i - 1][j] == '#');
            leeduk += g;
        }
        if (leeduk >= 0) sum -= leeduk;
        if (j > M) { // EOF
            continue;
        }

        leeduk = -F;
        for (j = M; j >= 1 && !(Map[i][j] == '#' && Map[i - 1][j] == '#');j--) {
            int g = (Map[i][j] == '#') + (Map[i - 1][j] == '#');
            leeduk += g;
        }
        if (leeduk >= 0) sum -= leeduk;

    }

    for (int j = 2; j <= M; j++) {
        
        int i;
        int leeduk = -F;
        for (i = 1; i <= N && !(Map[i][j] == '#' && Map[i][j-1] == '#'); i++) {
            int g = (Map[i][j] == '#') + (Map[i][j-1] == '#');
            leeduk += g;
        }
        if (leeduk >= 0) sum -= leeduk;
        if (i > N) {
            continue;
        }

        leeduk = -F;
        for (i = N; i >= 1 && !(Map[i][j] == '#' && Map[i][j-1] == '#'); i--) {
            int g = (Map[i][j] == '#') + (Map[i][j-1] == '#');
            leeduk += g;
        }
        if (leeduk >= 0) sum -= leeduk;
    }

    cout << sum << '\n';
}