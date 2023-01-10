#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
int dp[500002], canknockdown[500002][2];
pair<int, int> domino[500002];

signed main() {

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x, h; cin >> x >> h;
        domino[i] = {x, h};
    }

    sort(domino + 1, domino + N + 1);

    for (int i = 1; i <= N; i++) {
        int pt1 = i, pt2 = i - 1;
        while (pt2 >= 1 && domino[pt2].first >= domino[pt1].first - domino[pt1].second) {
            if (domino[pt2].first - domino[pt2].second < domino[pt1].first - domino[pt1].second) {
                pt1 = pt2;
            }
            pt2--; canknockdown[i][0]++;
        }

        int pt3 = i, pt4 = i + 1;
        while (pt4 <= N && domino[pt4].first <= domino[pt3].first + domino[pt3].second) {
            if (domino[pt4].first + domino[pt4].second > domino[pt3].first + domino[pt3].second) {
                pt3 = pt4;
            }
            pt4++; canknockdown[i][1]++;
        }
    }

    for (int i = 1; i <= N + 1; i++) dp[i] = 696974740;
    dp[1] = 0;

    for (int i = 1; i <= N; i++) {
        // 1. i번째를 오른쪽으로 넘어뜨린다.
        int can = canknockdown[i][1];
        dp[i + can + 1] = min(dp[i] + 1, dp[i + can + 1]);

        // 2. j번째를 왼쪽으로 넘어뜨린다.
        for (int j = i; j <= N; j++) {
            int c0 = canknockdown[j][0];
            if (c0 >= j - i) dp[j + 1] = min(dp[j + 1], dp[i] + 1);
        }
    }

    cout << dp[N + 1] << '\n';
}