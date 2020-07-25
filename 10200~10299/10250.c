#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, T, H, W, N, floor, order;
	char **answer;
	scanf("%d", &T);
	answer = (char**)malloc(sizeof(char*) * T);
	for (i = 0; i < T; ++i)
		answer[i] = (char*)malloc(sizeof(char) * 5);
	for (i = 0; i < T; ++i) {
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0) {
			floor = H;
			order = N / H;
		}
		else if (N / H == 0) {
			floor = N;
			order = 1;
		}
		else {
			floor = N % H;
			order = N / H + 1;
		}
		sprintf(answer[i], "%d%02d", floor, order);
	}
	for (i = 0; i < T; ++i) {
		printf("%s\n", answer[i]);
		free(answer[i]);
	}
	free(answer);
	return 0;
}