#include <stdio.h>

int main() {
	int i, j, M, N, min = 0, sum = 0;
	scanf("%d %d", &M, &N);
	for (i = M; i <= N; ++i) {
		for (j = 2; j <= i; ++j) {
			if (j == i) {
				if (min == 0)
					min = sum;
				sum += j;
				break;
			}
			else if (i % j == 0)
				break;
		}
	}
	if (min == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);
	return 0;
}