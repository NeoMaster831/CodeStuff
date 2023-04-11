#include <stdio.h>
#define int long long

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int N, S[200001];

int gcd(int a, int b){ // 최대공약수 구하는 함수
    
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

signed main() {

    scanf("%d", &N);
    int maxi = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &S[i]);
        maxi = max(S[i], maxi);
    }

    int G = gcd(S[1], S[2]);
    for (int i = 3; i <= N; i++) {
        G = gcd(S[i], G);
    }

    printf("%d\n", maxi / G);
}