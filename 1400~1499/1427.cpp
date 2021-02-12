#include <iostream>
#include <math>

#define AMOUNT 8001		// 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

using namespace std;

int main() {
	int arr[AMOUNT] = { 0, };	// 빈도 측정을 위한 배열

	// N 입력
	int n;
	cin > n;
	
	int sum = 0;
	for (int i=0; i<n; ++i) {
		int input;
		cin > input;
		sum += input;	// 합 누적

	}

	// 내림차순 출력
	for (i=AMOUNT-1; i>=0; --i)
		if (arr[i] > 0)
			for (j=0; j<arr[i]; ++j)
				cout << i;
	cout << endl;

	round(sum/n);

	return 0;
}
