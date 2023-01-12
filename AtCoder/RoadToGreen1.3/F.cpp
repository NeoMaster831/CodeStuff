#include <bits/stdc++.h>

using namespace std;

string S;

int main() {

    cin >> S;

    vector<char> newS;
    for (int i = 0; i < S.size(); i++) {
        if (i == S.size() - 1) {
            newS.push_back(S[i]);
            continue;
        }
        if (S[i] == 'g' && S[i + 1] == 'p') {
            newS.push_back('A');
            i++;
        }
        else if (S[i] == 'p' && S[i + 1] == 'p') {
            newS.push_back('B');
            i++;
        } else {
            newS.push_back(S[i]);
        }
    }

    int pcnt = 0, ans = 0;
    for (int i = 0; i < newS.size(); i++) {
        if (newS[i] == 'A') {

            int d[2] = { 0, 0 };
            ans += d[pcnt];

        } else if (newS[i] == 'B') {

            int d[2] = { -1, -1 };
            ans += d[pcnt];

        } else if (newS[i] == 'g') {

            int d[2] = { 0, 1 };
            ans += d[pcnt];
            if (pcnt == 0) pcnt++;
            else pcnt--;

        } else {

            int d[2] = { -1, 0 };
            ans += d[pcnt];
            if (pcnt == 0) pcnt++;
            else pcnt--;

        }
    }

    cout << ans << '\n';
}