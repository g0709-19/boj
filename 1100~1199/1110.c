#include <stdio.h>

int main() {
    int one, T, N, C = 0;
    scanf("%d", &N);
    T = N;
    while(1) {
        if (T >= 10) {
            one = T%10;
            T = T/10 + one;
            if (T >= 10)
                T %= 10;
            T += one * 10;
        } else {
            T += T*10;
        }
        ++C;
        if(N == T)
            break;
    }
    printf("%d", C);
    return 0;
}