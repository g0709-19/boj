#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, C, N, count = 0;
    double *score, sum, *average;
    scanf("%d", &C);
    average = (double*)malloc(sizeof(double)*C);
    for(i=0; i<C; ++i) {
        scanf("%d", &N);
        score = (double*)malloc(sizeof(double)*N);
        sum = 0.0;
        count = 0;
        for(j=0; j<N; ++j) {
            scanf("%lf", &score[j]);
            sum += score[j];
        }
        sum /= N;
        for(j=0; j<N; ++j) {
            if (score[j] > sum)
                ++count;
        }
        average[i] = count / (double)N * 100;
        free(score);
    }
    for(i=0; i<C; ++i)
        printf("%.3lf%%\n", round(average[i]*1000)*0.001);
    free(average);
    return 0;
}