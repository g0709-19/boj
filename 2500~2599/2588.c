#include <stdio.h>

int main() {
    int a, b;
    int A, B, C;
    scanf("%d %d", &a, &b);
    A = b/100;
    B = b/10;
    C = b-B*10;
    B = B-A*10;
    printf("%d\n", a*C);
    printf("%d\n", a*B);
    printf("%d\n", a*A);
    printf("%d\n", a*b);
    return 0;
}