#include <bits/stdc++.h>

using namespace std;

int N, B[100001];

int main() {
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%1d", &B[i]);
    }

    vector<int> s1;
    for (int i = 1; i <= N; i++) {
        if (B[i]) {
            for (int j = i; j <= N; j++) {
                s1.push_back(B[j]);
            }
            break;
        }
    }

    if (s1.empty()) { cout << 0 << '\n'; return 0; }

    int s2_len = s1.size();
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == 0) break;
        s2_len--;
    }
    
    int zerostart = s1.size() - s2_len;
    for (int i = 0; i < s1.size(); i++) {
        if (i >= zerostart) {
            cout << (s1[i - zerostart] | s1[i]);
        } else cout << s1[i];
    }
}