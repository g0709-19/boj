#include <stdio.h>

int main() {
    int H, M;
    scanf("%d %d", &H, &M);
    M -= 45;
    if (M < 0) {
        M += 60;
        if (--H < 0)
            H = 24+H;
    }
    printf("%d %d", H, M);
    return 0;
}