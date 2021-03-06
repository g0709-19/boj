#include <iostream>
#include <algorithm>

#define SIZE	1001

using namespace std;

int cost[SIZE] = { 0, };
int dp[SIZE] = { 0, };

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> cost[i];

	int answer = 0;

	for (int i = 1; i <= n; ++i) {
		int _max = 0;
		// 이전 값에서 작은 값만 탐색하여 최대 길이 선별
		for (int j = 0; j < i; ++j) {
			if (cost[j] < cost[i]) {
				_max = max(_max, dp[j]);
			}
		}
		dp[i] = _max + 1;
		answer = max(answer, dp[i]);
	}

	cout << answer << '\n';
	return 0;
}
