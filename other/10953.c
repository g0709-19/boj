#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	int* result;
	scanf("%d", &T);
	result = (int*)malloc(sizeof(int) * T);
	for (int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d,%d", &a, &b);
		result[i] = a + b;
	}
	for (int i = 0; i < T; ++i)
		printf("%d\n", result[i]);
	free(result);
	return 0;
}
