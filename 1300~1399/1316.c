#include <stdio.h>
#include <string.h>

int main() {
	int i, j, k, end, amount = 0, N, check, answer = 0;
	char words[101];
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", words);
		check = 0; //연속이 아닌 문자가 있는지 확인하는 값
		for (j = 0; j < strlen(words); ++j) {
			end = amount = 0;
			//j번째 문자가 words 에서 연속으로 나오는지 검사
			for (k = j; k < strlen(words); ++k) {
				if (words[j] == words[k]) {
					end = k;
					++amount;
				}
			}
			//j번째 문자가 연속이 아니라면 체크
			if (end - j + 1 != amount) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			++answer;
		}
	}
	printf("%d\n", answer);
	return 0;
}