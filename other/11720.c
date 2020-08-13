#include <stdio.h>

int main() {
    int i, N, sum = 0;
    char number[101];
    scanf("%d", &N);
    scanf("%s", number);
    for(i=0; i<N; ++i) {
        sum += number[i] - 48;
    }
    printf("%d", sum);
    return 0;
}