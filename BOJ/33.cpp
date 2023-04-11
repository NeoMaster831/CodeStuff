#include <iostream>
#include <algorithm>

using namespace std;
#define int long long

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int N, A[500001];

signed main() {

    cin >> N;

    int mini = 9076543212345678;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);

    // 1번 : mini + 1

    bool can1 = true;
    for (int i = 2; i <= N; i++) {
        if ((A[i] + 1) % (A[1] + 1) != 0 && A[i] % (A[1] + 1) != 0) {
            //cout << i << '\n';
            can1 = false;
            break;
        }
    }

    if (can1) { cout << A[1] + 1 << '\n'; return 0; }

    bool can2 = true;
    for (int i = 2; i <= N; i++) {
        if ((A[i] + 1) % A[1] != 0 && A[i] % A[1] != 0) {
            can2 = false;
            break;
        }
    }

    if (can2) cout << A[1] << '\n';
    else cout << 1 << '\n';
}