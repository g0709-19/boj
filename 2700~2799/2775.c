#include <stdio.h>

int bunyeo(int k, int n) {
	int i, sum = 0;
	if (k == 0)
		return n;
	else if (n == 1)
		return 1;
	else {
		for (i = 0; i < n; ++i)
			sum += bunyeo(k - 1, n - i);
		return sum;
	}
}

int main() {
	int i, T, k, n;
	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		scanf("%d %d", &k, &n);
		printf("%d\n", bunyeo(k, n));
	}
	return 0;
}