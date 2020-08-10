#include <stdio.h>

int main() {
	int i, j, X, temp = 0;
	scanf("%d", &X);
	for (i = 1;; ++i) {
		if (X <= (temp = i * (i + 1) / 2)) {
			if (i % 2 == 0) {
				for (j = 0; j < i; ++j) {
					if (temp == X) {
						printf("%d/%d\n", i - j, j + 1);
						return 0;
					}
					--temp;
				}
			}
			else {
				for (j = i - 1; j >= 0; --j) {
					if (temp == X) {
						printf("%d/%d\n", i - j, j + 1);
						return 0;
					}
					--temp;
				}
			}
			break;
		}
	}
	return 0;
}