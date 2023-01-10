#include <bits/stdc++.h>

using namespace std;
#define INF 98765432

int N, M;
int dp[2][310][310]; // b, le, r
int dist[3][310][310]; // 같은 곳?, le, r
vector<int> lev, riv;

bool cmp(const int left, const int right) {
    return abs(left) < abs(right);
}

int solve(int b, int le, int r, int spent) {

    if (spent >= M) return 0; // Base case: if candy is all gone

    int& cache = dp[b][le][r];
    if (cache != -1) return cache;

    // b == 0 : 왼쪽에 있음, b == 1 : 오른쪽에 있음
    if (b) {

        cache = max(
            solve(1, le, r + 1, spent + dist[1][r][r + 1]) + M - spent,
            solve(0, le + 1, r, spent + dist[0][le + 1][r]) + M - spent
        );

    } else {
        
        cache = max(
            solve(0, le + 1, r, spent + dist[2][le][le + 1]) + M - spent,
            solve(1, le, r + 1, spent + dist[0][le][r + 1]) + M - spent
        );

    }

    cout << "Left?Right?: " << b << ", left: " << le << ", right: " << r << ", can eat:" << M - spent << ", CACHE: " << cache << '\n';

    return cache;
}

int main() {

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int coord; cin >> coord;
        if (coord < 0) lev.push_back(coord);
        else riv.push_back(coord);
    }

    lev.push_back(-INF); riv.push_back(INF);
    sort(lev.begin(), lev.end(), cmp);
    sort(riv.begin(), riv.end(), cmp);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[0][i][j] = -1; dp[1][i][j] = -1;
        }
    }

    dist[2][0][1] = -lev[0]; dist[1][0][1] = riv[0];
    for (int i = 0; i < lev.size() - 1; i++) {
        dist[2][i + 1][i + 2] = abs(lev[i + 1] - lev[i]);
    }
    for (int i = 0; i < riv.size() - 1; i++) {
        dist[1][i + 1][i + 2] = abs(riv[i + 1] - riv[i]);
    }
    for (int i = 0; i < lev.size(); i++) {
        for (int j = 0; j < riv.size(); j++) {
            dist[0][i + 1][j + 1] = abs(riv[j] - lev[i]);
        }
    }

    cout << '\n';
    for (int i = 0; i < lev.size() - 1; i++) {
        for (int j = 0; j < riv.size() - 1; j++) {
            cout << dist[0][i + 1][j + 1] << ' ';
        }
        cout << '\n';
    } cout << "============================\n"; for (int i = 1; i < lev.size(); i++) {
        cout << dist[2][i - 1][i] << ' ';
    } cout << "\n============================\n"; for (int j = 1; j < riv.size(); j++) {
        cout << dist[1][j - 1][j] << ' ';
    }
    cout << "\n\n";

    cout << max(solve(1, 0, 1, riv[0]), solve(0, 1, 0, -lev[0])) << '\n';

    cout << dp[0][1][1];
}