#include <iostream>
#include <vector>

#define INF	10000

using namespace std;

int N;
vector<vector<int>> costs;
vector<vector<int>> dp;

int paint(int n, int last) {
	if (n < N) {
		if (dp[n][last]) {
			return dp[n][last];
		}

		int max = INF;
		for (int i = last; i < last+2 && i < n+1; ++i) {
			int root = costs[n][i];
			int sub = paint(n + 1, i);
			int sum = root + sub;
			if (sum > max || max == INF)
				max = sum;
		}
		return dp[n][last] = max;
	}
	return 0;
}

int main() {
	cin >> N;
	costs = vector<vector<int>>(N);
	dp = vector<vector<int>>(N+1);
	dp[N] = vector<int>(N);

	for (int i = 0; i < N; ++i) {
		int row = i + 1;
		costs[i] = vector<int>(row);
		dp[i] = vector<int>(row);
		for (int j = 0; j < row; ++j) {
			cin >> costs[i][j];
			dp[i][j] = 0;
		}
	}

	cout << paint(0, 0) << '\n';
	
	return 0;
}
