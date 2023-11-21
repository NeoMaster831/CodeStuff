#include <bits/stdc++.h>

using namespace std;
#define int long long

priority_queue<int, vector<int>, greater<int> > pq;

void rec(string s) {
    int stoi = atoll(s.c_str());
    pq.push(stoi);
    for (int i = 0; i <= 9; i++) {
        if (i + 48 > s[0]) {
            string news = (char)(i + 48) + s;
            rec(news);
        }
    }
}

signed main() {
    int n; cin >> n;
    for (int i = 0; i <= 9; i++) {
        string inp(1, (char)(i + 48));
        rec(inp);
    }
    if (n > pq.size()-1) {
        cout << -1 << '\n'; return 0;
    }
    while (n--) {
        pq.pop();
    }
    //cout << pq.size() << '\n';
    cout << pq.top() << '\n';
}