#include <iostream>
#include <algorithm>

#define SIZE	10001

using namespace std;

int cost[SIZE] = { 0, };
int dp[SIZE] = { 0, };

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> cost[i];

	dp[1] = cost[1];
	dp[2] = cost[1] + cost[2];

	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 2] + cost[i], dp[i - 3] + cost[i - 1] + cost[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n] << '\n';
	return 0;
}
