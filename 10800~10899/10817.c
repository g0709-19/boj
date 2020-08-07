#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (A > B) {
        if (B > C)
            printf ("%d", B);
        else if (A < C)
            printf("%d", A);
        else
            printf("%d", C);
    } else if (B > A) {
        if (A > C)
            printf("%d", A);
        else if (B < C)
            printf("%d", B);
        else
            printf("%d", C);
    } else if (A == B)
        printf("%d", A);
    else
        printf("%d", C);
    return 0;
}