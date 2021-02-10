#include <iostream>

#define AMOUNT 10001

int main() {
	int i, j, temp, n;
	int arr[AMOUNT] = { 0, };

	scanf("%d", &n);
	for (i=0; i<n; ++i) {
		scanf("%d", &temp);
		arr[temp] += 1;	// 빈도 측정
	}

	// 출력
	for (i=0; i<AMOUNT; ++i)
		if (arr[i] != 0)
			for (j=0; j<arr[i]; ++j)
				printf("%d\n", i);
	return 0;
}