#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> coin(N);

	for (int i = 0; i < N; ++i)
		cin >> coin[i];

	int sum, count;
	sum = count = 0;

	while (sum != K) {
		int temp = 0;
		for (int i = 0; i < N; ++i)
			// 항상 최대값을 선택해서 합함
			if (sum + coin[i] <= K)
				temp = max(temp, coin[i]);
		sum += temp;
		++count;
	}

	cout << count << '\n';
	return 0;
}
