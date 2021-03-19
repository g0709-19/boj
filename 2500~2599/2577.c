#include <stdio.h>

int main() {
    int i, A, B, C, count[10] = {0,};
    char sum[10];
    scanf("%d %d %d", &A, &B, &C);
    sprintf(sum, "%d", A*B*C);
    for(i=0; i<10; ++i) {
        ++count[sum[i]-48];
    }
    for(i=0; i<10; ++i) {
        printf("%d\n", count[i]);
    }
    return 0;
}