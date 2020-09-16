#include <stdio.h>

int main() {
    int i, j, k, T, R;
    char S[21];
    scanf("%d", &T);
    for(i=0; i<T; ++i) {
        scanf("%d %s", &R, S);
        for(j=0; S[j] != NULL; ++j) {
            for(k=0; k<R; ++k) {
                printf("%c", S[j]);
            }
        }
        printf("\n");
    }
    return 0;
}