#include <bits/stdc++.h>

using namespace std;

int H, W;
string S[500001];

int main() {

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int X = 0, Y = 0;
    int Q; cin >> Q; while (Q--) {
        int a, b; cin >> a >> b;
        X += a + H;
        Y += b + W;
    }

    int share[2] = { X / H, Y / W };
    int A = X % H, B = Y % W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W / 2; j++) {
            if (share[0] % 2 == 1) swap(S[i][j], S[i][W - j - 1]);
        }
    }
    for (int i = 0; i < H / 2; i++) {
        if (share[1] % 2 == 0) swap(S[i], S[H - i - 1]);
    }

    cout << A << ' ' << B << '\n';
    for (int i = A + H - 1; i > A - 1; i--) {
        for (int j = B - 1; j < B + W - 1; j++) {
            cout << S[i % H][j % W];
        }
        cout << '\n';
    }
}