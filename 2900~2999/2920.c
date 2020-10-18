#include <stdio.h>

int main() {
    int i, array[8];
    for(i=0; i<8; ++i) {
        scanf("%d", array+i);
    }
    if(array[0] == 1) {
        for(i=0; i<7; ++i) {
            if (array[i]+1 != array[i+1]) {
                printf("mixed");
                return 0;
            }
        }
        printf("ascending");
    }
    else if(array[0] == 8) {
        for(i=0; i<7; ++i) {
            if (array[i]-1 != array[i+1]) {
                printf("mixed");
                return 0;
            }
        }
        printf("descending");
    }
    else
        printf("mixed");
    return 0;
}