#include <stdio.h>
int main() {
    int num = 0;
    scanf("%d", &num);
    
    printf("%d\n", num*(-1));
    printf("%d\n", num);
    
    if (num && num == (-1)*num) {
        printf("Congratulation! Flag is FLAG{fake_flag}\n");
    } else {
        printf("Incorrect.\n");
    }
    return 0;
}