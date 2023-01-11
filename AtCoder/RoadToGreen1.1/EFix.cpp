#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
string s;
 
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
            while (l >= 0 && rear[l] == 'A') {
                l--;
            } l++;
 
            ans += i + 1 - l;
            rear[l] = 'D'; rear[i + 1] = 'A';
        }
    }
 
    cout << ans << '\n';
}