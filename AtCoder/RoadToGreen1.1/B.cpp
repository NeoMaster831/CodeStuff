#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int N; cin >> N;
    
    stack<char> ans;
    while (N != 0) {
        if (N % 2 == 1) {
            N--;
            ans.push('A');
        } else {
            N /= 2;
            ans.push('B');
        }
    }

    while (!ans.empty()) {
        cout << ans.top(); ans.pop();
    }

}