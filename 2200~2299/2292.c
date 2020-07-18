#include <stdio.h>

int main() {
	int i, N, end = 1;
	scanf("%d", &N);
	if (N > 1) {
		for (i = 1; 1; ++i) {
			end += 6 * i;
			if (N <= end) {
				printf("%d", i + 1);
				break;
			}
		}
	}
	else {
		printf("%d", end);
	}
	return 0;
}