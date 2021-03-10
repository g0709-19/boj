#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> dp[i];

	int answer = dp[1];

	for (int i = 2; i <= n; ++i) {
		// 이전의 합이 음수거나, 이전의 합 + 현재 값이 음수라면 더하지 않음
		if (dp[i - 1] > 0 && dp[i - 1] + dp[i] > 0)
			dp[i] += dp[i - 1];
		answer = max(answer, dp[i]);
	}

	cout << answer << '\n';
	return 0;
}
