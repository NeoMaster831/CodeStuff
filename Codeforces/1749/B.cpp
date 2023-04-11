#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
pair<int, int> monster[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp; monster[i].first = inp;
    } for (int i = 1; i <= N; i++) {
        int inp; cin >> inp; monster[i].second = inp;
    }

    int ptr1 = 1, ptr2 = N;
    int ans = 0;
    while (ptr1 <= ptr2) {
        
        int b1 = monster[ptr1].second, b2 = monster[ptr2].second;
        if (b1 < b2) {

            int a1 = monster[ptr1].first;
            ans += a1;
            ptr1++;
            monster[ptr1].first += b1;

        } else {
            
            int a2 = monster[ptr2].first;
            ans += a2;
            ptr2--;
            monster[ptr2].first += b2;

        }

    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}