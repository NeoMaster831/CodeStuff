#include <bits/stdc++.h>

using namespace std;

int N, S[6], L[10];

int main() {
    
    cin >> N;

    N--;
    int ptr = 0;
    while (N >= 10) {
        S[ptr] = N % 10;
        N /= 10;
        ptr++;
    }

    int divider = ptr == 5 ? 9 : 10;
    S[ptr] = N % divider; N /= divider;

    // initial 배열
    L[8] = S[0];
    L[9] = L[7] = S[1];
    L[5] = L[6] = S[2];
    L[4] = S[3];
    L[3] = S[4];
    L[1] = L[2] = S[5] + 1;

    for (int i = 1; i <= 9; i++) {
        cout << L[i];
    }
    cout << '\n';
}