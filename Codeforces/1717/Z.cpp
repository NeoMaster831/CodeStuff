#include <bits/stdc++.h>

using namespace std;
#define int long long

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int N;

void solve() {

    cin >> N;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}