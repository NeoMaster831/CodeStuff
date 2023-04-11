#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define MAX 10101010
 
int preprocess[MAX + 1];
 
void eratostenes() {
    for (int i = 2; i <= MAX; i++) {
        if (preprocess[i] != i) continue;
        for (int j = i * i; j <= MAX; j += i) {
            preprocess[j] = min(preprocess[j], i);
        }
    }
}

vector<int> soinsubunhae(int x) {
    vector<int> ans;
    while (x > 1) {
        int divisor = preprocess[x];
        while (x % divisor == 0) {
            x /= divisor;
        }
        ans.push_back(divisor);
    }
    return ans;
}
 
int gcd(int a, int b){
    
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
 
void solve() {
    
    int A, B;
    cin >> A >> B;
    
    int orig_gcd = gcd(A, B);
    if ((orig_gcd == 1 && A == 1) || orig_gcd != 1) { cout << 0 << '\n'; return; }
    if (B - A == 1) { cout << -1 << '\n'; return; }
 
    int diff = B - A;

    int ans = 876543756374;
    vector<int> fact = soinsubunhae(diff);
    for (int i = 0; i < fact.size(); i++) {
        int x = fact[i] - (A % fact[i]);
        ans = min(ans, x);
    }

    cout << ans << '\n';
}
 
signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
 
    for (int i = 1; i <= MAX; i++) {
        preprocess[i] = i;
    }
    eratostenes();
 
    while (T--) solve();
}