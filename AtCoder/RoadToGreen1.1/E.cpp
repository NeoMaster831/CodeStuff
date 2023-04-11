#include <bits/stdc++.h>

using namespace std;
#define int long long

string s;

/*
Found the error with the test case:
ABCABCAAAAAAAAAAAAAAAAAAAAAAAAABCCCCCCCCCBCABCABCABCABCAAAABCBCBCBCBCBC
*/

signed main() {

    cin >> s;
    if (s.size() == 1) { cout << 0 << '\n'; return 0; }

    vector<char> rear;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            rear.push_back('D');
            i++;
        }
        else {
            rear.push_back(s[i]);
        }
    }

    int ans = 0;
    if (rear.size() == 1) { cout << 0 << '\n'; return 0; }

    for (int i = 0; i < rear.size() - 1; i++) {
        if (rear[i] == 'A' && rear[i + 1] == 'D') {

            int l = i - 1;
            while (l >= 0 && rear[l] != 'B' && rear[l] != 'C') {
                l--;
            } l++;
            while (rear[l] == 'D') {
                l++;
            }

            int r = l + 1;
            while (r < rear.size() && rear[r] != 'B' && rear[r] != 'C') {
                if (rear[r] == 'D') {
                    ans += r - l; l++;
                }
                r++;
            }
            i = r;
        }
    }

    cout << ans << '\n';
}