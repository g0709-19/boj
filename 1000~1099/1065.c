#include <stdio.h>

int hansu(int number) {
    int i = 0, previous = 0, d = 0, d2 = 0;
    while(number!=0) {
        if(i == 0);
        else if(i == 1)
        	d = number%10 - previous;
        else
        	if(d != (d2 = number%10 - previous))
        		return 0;
        	else
        		d = d2;
        previous = number%10;
        number/=10;
        ++i;
    }
    return 1;
}

int main() {
    int i, N;
    int count = 0;
    scanf("%d", &N);
    for(i=1; i<=N; ++i) {
        if(hansu(i) == 1) {
            ++count;
        }
    }
    printf("%d", count);
    return 0;
}