#include <stdio.h>

int main() {
    int i, T, A, B;
    scanf("%d", &T);
    for(i=1; i<=T; ++i) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A+B);
    }
    return 0;
}