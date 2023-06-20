#include <bits/stdc++.h>

using namespace std;
#define QWORD unsigned long long

int main() {
    QWORD p = 65287;
    QWORD q = 65419;
    QWORD eulern = (p - 1) * (q - 1);
    QWORD e = 201326609;
    QWORD n = p * q;
    QWORD d = 1384538333;

    QWORD first[] = {3571245376,2709774306,3278103302,4191347304,3290047497,714850555,2588811957,2100883354,2975830687,2664856559, 2580409063};
    
    for (int k = 0; k < 11; k++) {
        QWORD v4 = 1;
        for (QWORD i = 0; i < d; i++) {
            v4 = first[k] * v4 % n;
        }
        while (v4) {
            unsigned char s = v4 % 256;
            cout << s;
            v4 /= 256;
        }
    }
    //DH{_RSA_1s_pub1ic-pr1v4te-key_crypt0gr@phy!}
}