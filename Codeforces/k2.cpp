#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const unsigned char F[16] = {
        0x0D, 0x05, 0x06, 0x35,
        0x42, 0x09, 0x7C, 0x75,
        0x0E, 0x25, 0x26, 0x12, 
        0x24, 0x1F, 0x3D, 0x48
    };
    int k;
    cin >> k;

    // Guess the first flag: DIMI{...} so the first WILL be 68 (D).
    while (k--) {
        int q, idx;
        cin >> q >> idx;
        // idx = 0~15
        for (int i = 0; i < 255; i++) {
            if ((q ^ i) + idx == F[idx]) cout << i << ' ';
        }
        cout << '\n';

    }
    
    // Fuck this problem, the array was DIMI{EA7Y_C_X@R}

    return 0;
}