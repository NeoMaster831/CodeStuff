#include <iostream>
 
using namespace std;
#define int long long
 
int N, S[200001];
 
int gcd(int a, int b){
    
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
 
void solve() {
    
    cin >> N;
    int maxi = -1;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        maxi = max(S[i], maxi);
    }
 
    int G = gcd(S[1], S[2]);
    for (int i = 3; i <= N; i++) {
        G = gcd(S[i], G);
    }
 
    cout << maxi / G << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}