#include <stdio.h>

int main() {
    int i, N, T, MAX, MIN;
    scanf("%d", &N);
    for(i=0; i<N; ++i) {
        scanf("%d", &T);
        if (i == 0) {
            MAX = T;
            MIN = T;
        }
        if (T > MAX)
            MAX = T;
        if (T < MIN)
            MIN = T;
    }
    printf("%d %d", MIN, MAX);
    return 0;
}