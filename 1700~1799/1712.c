#include <stdio.h>

int main() {
	int x, A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (B < C) {
		x = A / (C - B) + 1;
	}
	else {
		x = -1;
	}
	printf("%d\n", x);
	return 0;
}