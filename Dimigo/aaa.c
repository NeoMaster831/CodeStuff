#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long nums[2345678];
long long num_count = 0;

int main() {

    for (long long k = 2; k <= 1000000; ++k) {
        long long val = 1 + k;
        long long p = k*k;
        for (int cnt = 3; cnt <= 63; ++cnt) {
            val += p;
            if (val > 1e18) break;
            nums[num_count++] = val;
            if (p > (long long)(1e18) / k) break;
            p *= k;
        }
    }
    
    int _ = 0, __ = 1;
    scanf("%d", &__);

    for (int _ = 0; _ < __; ++_) {
        long long n;
        scanf("%lld", &n);
        if (n < 3)
        {
            printf("NO\n");
            continue;
        }
        long long d = 4*n - 3;
        long long sq = sqrt(d);
        long long sqd = -1;
        for (long long i = max(0ll, sq - 5); i <= sq + 5; ++i) {
            if (i*i == d)
            {
                sqd = i;
                break;
            }
        }
        if (sqd != -1 && (sqd - 1) % 2 == 0 && (sqd - 1) / 2 > 1)
        {
            printf("YES\n");
            continue;
        }

        bool found = false;
        for (int i = 0; i < num_count; i++) {
            if (nums[i] == n) {
                printf("YES\n");
                found = true;
                continue;
            }
        }
        if (!found) printf("NO\n");
    }

    return 0;
}