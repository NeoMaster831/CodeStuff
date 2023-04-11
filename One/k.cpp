#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <memory.h>
#include <stack>

using namespace std;
#define int long long
#define INF 12345678900000

int N, AURA, HP;
pair<int, pair<int, int> > dp[5010][5010];
pair<int, int> attack[5010];

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, INF, sizeof(dp));

    cin >> N >> AURA >> HP;
    for (int i = 1; i <= N; i++)cin >> attack[i].first >> attack[i].second;

    dp[0][0] = { 0, {0, 0} };
    for (int idx = 1; idx <= N; idx++) {

        int aura = attack[idx].first;
        int hp = attack[idx].second;
        // 1. hp 소모
        // 2. Aura 소모, hp 비소모

        for (int knapsack = 0; knapsack < HP; knapsack++) {
            if (dp[idx - 1][knapsack].first >= INF) continue;
            if (knapsack + hp < HP && hp != -1) {
                if (dp[idx][knapsack + hp].first >= dp[idx - 1][knapsack].first) {
                    dp[idx][knapsack + hp] = {dp[idx- 1][knapsack].first, { knapsack, 1} };
                }
            }
            if (aura != -1) {
                int x = dp[idx - 1][knapsack].first + aura;
                if (x > AURA && hp == -1 && dp[idx - 1][knapsack].first <= AURA) x = AURA;
                if (dp[idx][knapsack].first >= x) {
                    dp[idx][knapsack] = { x, { knapsack, 0}};
                }
            }
        }

    }

    for (int i = 1; i <= N; i++) {
        //for (int j = 0; j < HP; j++) cout << dp[i][j].first << ' ';
        //cout << '\n';
    }

    for (int i = 0; i < HP; i++) {
        if (dp[N][i].first <= AURA) {
            cout << "YES" << '\n';
            int kn = i;
            stack<char> st;
            for (int j = N; j >= 1; j--) {
                if (dp[j][kn].second.second == 0) st.push('A');
                else st.push('L');
                kn = dp[j][kn].second.first;
            }

            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';
}