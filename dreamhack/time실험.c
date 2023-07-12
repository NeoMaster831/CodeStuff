#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    srand(1909094400);
    int v4 = rand();
    int v7 = v4 + rand();

    printf("%d %d", v4, v7);
}