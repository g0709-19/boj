#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, N, M;
    double sum = 0.0, *score;
    scanf("%d", &N);
    score = (double*)malloc(sizeof(double)*N);
    for(i=0; i<N; ++i) {
        scanf("%lf", &score[i]);
        if (i == 0)
            M = score[i];
        if (score[i] > M)
            M = score[i];
    }
    for(i=0; i<N; ++i) {
        sum += score[i] / M*100;
    }
    printf("%.2lf", sum/N);
}