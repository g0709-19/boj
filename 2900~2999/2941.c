#include <stdio.h>
#include <string.h>

int main() {
	char alphabets[8][4] = {
		"c=",
		"c-",
		"dz=",
		"d-",
		"lj",
		"nj",
		"s=",
		"z="
	};
	char* temp, * search, word[101] = { 0 };
	int i, j, check = 0, check2 = 0, answer = 0;
	scanf("%s", word);
	//크로아티아 알파벳에 해당되는 수를 구함
	for (i = 0; i < 8; ++i) {
		temp = alphabets[i];
		do {
			check = 0; //문자열에 해당 크로아티아 알파벳이 남아있는지 검사하는 값
			search = strstr(word, temp);
			if (search != NULL) {
				//이미 검사한 알파벳을 제외하기 위한 작업
				for (j = 0; j < strlen(temp); ++j) {
					search[j] = 'A';
				}
				++answer;
				check = 1;
			}
		} while (check != 0);
	}
	//크로아티아 알파벳을 제외한 문자들의 수를 구함
	for (i = 0; i < strlen(word); ++i) {
		if (word[i] != 'A') {
			++answer;
		}
	}
	printf("%d\n", answer);
	return 0;
}