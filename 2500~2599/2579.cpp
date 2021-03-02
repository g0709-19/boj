#include <iostream>
#include <vector>

#define INF		10001

using namespace std;

int N;
vector<int> cost;
vector<vector<int>> dp;

int stair(int n, int last) {
	if (n > 0) {
		if (dp[n][last]) return dp[n][last];
		int max = INF;
		for (int i = 1; i <= 2; ++i) {
			if (last == 1 && i == 1) continue;
			int c = cost[n] + stair(n - i, i);
			if (c > max || max == INF)
				max = c;
		}
		return dp[n][last] = max;
	}
	return 0;
}

int main() {
	cin >> N;
	cost = vector<int>(N + 1);
	dp = vector<vector<int>>(N+1);
	cost[0] = 0;

	for (int i = 1; i <= N; ++i) {
		dp[i] = vector<int>(3);
		cin >> cost[i];
	}

	cout << stair(N, 0);
	return 0;
}
