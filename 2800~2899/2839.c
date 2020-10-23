#include <stdio.h>

int main() {
	int i, j, N, count = -1;
	scanf("%d", &N);
	for (i = 0; i <= 1666; ++i) {
		for (j = 0; j <= 1000; ++j) {
			if (N == 3 * i + 5 * j) {
				count = i + j;
				break;
			}
		}
		if (count != -1)
			break;
	}
	printf("%d\n", count);
	return 0;
}