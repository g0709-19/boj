#include <stdio.h>

int main() {
	int i, j, N, input, count = 0;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &input);
		for (j = 2; j <= input; ++j) {
			if (input == j) {
				++count;
				break;
			}
			else if (input % j == 0)
				break;
		}
	}
	printf("%d\n", count);
	return 0;
}