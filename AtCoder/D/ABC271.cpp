#include <bits/stdc++.h>

using namespace std;
bool dp[102][10001][2];

int N, S, card[101][2]; // 0 : front, 1 : back

vector<int> solve(int idx, int val, bool fb) { // idx, 현재까지 더한거, idx번째 뒤집음?

    if (idx == N) {
        if (val == S) return { fb }; // idx - 1번째를 리턴
        else return {};
    }

    bool& cache = dp[idx][val][fb];
    if (cache) return {};

    cache = true;
    vector<int> front = solve(idx + 1, val + card[idx + 1][0], 0);
    vector<int> back = solve(idx + 1, val + card[idx + 1][1], 1);

    /*
    cout << "Idx: " << idx << ", val: " << val << ", Front?Back?: " << fb << '\n';
    for (int i = 0; i < front.size(); i++) {
        cout << front[i] << ' ';
    } cout << "\n";
    for (int i = 0; i < back.size(); i++) {
        cout << back[i] << ' ';
    } cout << '\n';
    */

    if (front.empty()) {
        if (!back.empty()) back.push_back(fb);
        return back;
    } else {
        front.push_back(fb);
        return front;
    }
}

int main() {

    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> card[i][0] >> card[i][1];
    }

    vector<int> ans = solve(1, card[1][0], 0);
    vector<int> ans2 = solve(1, card[1][1], 1);
    if (ans.empty()) {
        if (ans2.empty()) cout << "No" << '\n';
        else {
            cout << "Yes" << '\n';
            for (int i = ans2.size() - 1; i >= 0; i--) {
                if (ans2[i] == 0) cout << "H";
                else cout << "T";
            }
        }
    }
    else {
        cout << "Yes" << '\n';
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] == 0) cout << "H";
            else cout << "T";
        }
    }
}