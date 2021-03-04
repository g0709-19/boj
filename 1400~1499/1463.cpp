#include <iostream>
#include <vector>
#include <algorithm>

#define INF		1000001

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> dp;
	if (N > 3)
		dp = vector<int>(N+1);
	else
		dp = vector<int>(4);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i=4; i<=N; ++i) {
		int a, b, c;
		a = b = c = INF;
		if (i%3 == 0)
			a = dp[i/3];
		if (i%2 == 0)
			b = dp[i/2];
		c = dp[i-1];
		dp[i] = min(min(a, b), c) + 1;
	}

	cout << dp[N] << '\n';
	return 0;
}
