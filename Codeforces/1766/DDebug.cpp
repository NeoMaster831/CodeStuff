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

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 19; i++) {
        if (gcd(282144 + i, 977777 + i) != 1) cout << i << '\n';
    }
    cout << "END" << '\n';
}