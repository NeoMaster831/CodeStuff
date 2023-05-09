#include <iostream>

using namespace std;
#define int long long

signed main() {
    int v4 = 0x62f0aaba;
    int v3 = 0xa1f2ddf600;
    int v2 = 0x2232c1f8e3;
    int v1 = 0x517f9764;
    
    cout << hex << ((v3 ^ v2) ^ v1) << '\n';
    cout << v4 + v3 << '\n';
    cout << v3 + v2 << '\n';
    cout << v2 + v1 << '\n';
    cout << v4 + v1 << '\n';
}