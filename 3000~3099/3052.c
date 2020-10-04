#include <stdio.h>

int main() {
    int i, j, temp, count[43] = {0,}, answer = 0;
    for(i=0; i<10; ++i) {
        scanf("%d", &temp);
        ++count[temp%42];
    }
    for(i=0; i<43; ++i) {
        if (count[i] != 0)
            ++answer;
    }
    printf("%d", answer);
    return 0;
}