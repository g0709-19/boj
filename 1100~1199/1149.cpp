#include <iostream>
#include <vector>

#define INF	1001
#define RGB	3

using namespace std;

int N;
vector<vector<int>> costs;
vector<vector<int>> dp;

int paint(int n, int last) {
	if (n >= 0) {
		if (last != INF && dp[n][last]) return dp[n][last];

		int min = INF;
		for (int i = 0; i < RGB; ++i) {
			if (last == i) continue;
			int root = N == n ? 0 : costs[n][i];
			int sub = paint(n - 1, i);
			int sum = root + sub;
			if (sum < min || min == INF)
				min = sum;
		}
		if (last == INF)
			return min;
		return dp[n][last] = min;
	}
	return 0;
}

int main() {
	cin >> N;
	costs = vector<vector<int>>(N);
	dp = vector<vector<int>>(N+1);
	dp[N] = vector<int>(RGB);

	for (int i = 0; i < N; ++i) {
		costs[i] = vector<int>(RGB);
		dp[i] = vector<int>(RGB);
		for (int j = 0; j < RGB; ++j) {
			cin >> costs[i][j];
			dp[i][j] = 0;
		}
	}

	cout << paint(N, INF) << '\n';
	
	return 0;
}
