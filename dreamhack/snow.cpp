#include <iostream>
#include <cstring>

using namespace std;
#define QWORD unsigned long long
#define WORD unsigned char

WORD b140003000[] = {
    0x24, 0x27, 0x13, 0xC6, 0xC6, 0x13, 0x16, 0xE6, 0x47, 0xF5, 0x26, 0x96, 0x47, 0xF5, 0x46, 0x27, 0x13, 0x26, 0x26, 0xc6, 0x56, 0xf5, 0xc3, 0xc3, 0xf5, 0xe3, 0xe3
};

int main() {
    for (int j = 0; j < 0x1C; j++) {
        for (WORD i = 0; i <= 255; i++) {
            if ((WORD)((WORD)(i << 4) | (WORD)(i >> 4)) == b140003000[j]) {
                cout << (char)i;
                break;
            }
        }
    }
}