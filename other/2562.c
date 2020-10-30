#include <stdio.h>

int main() {
    int i, temp, max[2];
    for(i=0; i<9; ++i) {
        scanf("%d", &temp);
        if (i == 0) {
            max[0] = temp;
            max[1] = 0;
        }
        if (temp > max[0]) {
            max[0] = temp;
            max[1] = i;
        }
    }
    printf("%d\n%d", max[0], max[1]+1);
    return 0;
}