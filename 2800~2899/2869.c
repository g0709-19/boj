#include <stdio.h>
#include <math.h>

int main() {
	int A, B, V, answer;
	scanf("%d %d %d", &A, &B, &V);
	answer = ceil((double)(V-B) / (double)(A-B));
	printf("%d", answer);
	return 0;
}