#include <iostream>

using namespace std;
#define int long long

signed main() {

    for (int v1 = 0; v1 <= 0xB470421E; v1++) {

        int v4 = 0xB470421E - v1;
        int v2 = 0x2284419047 - v1;
        int v3 = 0xC4259FEEE3 - v2;

        if (((v3 ^ v2) ^ v1) == 0x8391639987) {
            cout << hex << v4 << ' ' << v3 << ' ' << v2 << ' ' << v1 << '\n';
            break;
        }
    }
}