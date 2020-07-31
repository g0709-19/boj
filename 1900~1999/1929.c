#include <stdio.h>

int main() {
	int i, j, M, N;
	int prime[1000001] = { 1, 1 };
	scanf("%d %d", &M, &N);
	for (i = 2; i <= N; ++i) {
		if (prime[i] == 1)
			continue;
		for (j = i + i; j <= N; j += i)
			prime[j] = 1;
	}
	for (i = M; i <= N; ++i) {
		if (prime[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}