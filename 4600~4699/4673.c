#include <stdio.h>
 
int d(int n) {
    int one, two, three, four, five;
    one = n/10000;
    two = n%10000/1000;
    three = n%10000%1000/100;
    four = n%10000%1000%100/10;
    five = n%10000%1000%100%10;
    return n+one+two+three+four+five;
}
 
int main() {
	int i, n;
	int exist[10000] = {0,};
	for(i=1; i<=10000; ++i) {
		for(n=i; n<=10000; n=d(n)) {
			if(exist[n] == 0) {
				exist[n] = 1;
			}
			else if(exist[n] == 1) {
				exist[n] = 2;
			}
		}
	}
	for(i=1; i<=10000; ++i) {
		if(exist[i] == 1) {
			printf("%d\n", i);
		}
	}
    return 0;
}