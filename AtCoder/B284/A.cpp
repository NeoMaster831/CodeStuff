#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> ans;

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        ans.push_back(s);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }

}