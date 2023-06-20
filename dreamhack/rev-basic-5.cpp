#include <bits/stdc++.h>

using namespace std;
#define WORD unsigned char

WORD b[] = { 0xAD, 0xD8, 0xCB,0xCb, 0x9D, 0x97, 0xCB, 0xC4, 0x92, 0xA1, 0xD2, 0xD7,
0xD2, 0xD6, 0xA8, 0xA5, 0xDC, 0xC7, 0xAD, 0xA3, 0xA1, 0x98, 0x4C};

int main() {
    
    for (int i = 0; i <= 0xFF; i++) {

        WORD now = i;
        for (int j = 0; j < 0x18; j++) {
            now = b[j] - now;
        }
        if (now == 0) {
            WORD r = i;
            cout << r;
            for (int j = 0; j < 0x18; j++) {
                r = b[j] - r;
                cout << r;
            }
            cout << '\n';
        }
    }
}