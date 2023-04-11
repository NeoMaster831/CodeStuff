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

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    
    int A, B, C, D; cin >> A >> B >> C >> D;
    int xA = gcd(A, B), xC = gcd(C, D);
    A /= xA; B /= xA; C /= xC; D /= xC;

    //cout << A << B << C << D << '\n';
    if ((A == 0 && C != 0) || (A != 0 && C == 0)) {
        cout << 1 << '\n'; return;
    }

    if (B != D) { A *= lcm(B, D) / B; C *= lcm(B, D) / D; }
    if (A == C) { cout << 0 << '\n'; return; }
    if (C % A == 0 || A % C == 0) { cout << 1 << '\n'; return; }
    cout << 2 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}