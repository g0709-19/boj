#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	int dp[30][30] = { 0, };
	for (int i = 1; i < 30; ++i)
		dp[1][i] = i;	// 1행은 1, 2, 3, ...
	for (int i = 2; i < 30; ++i)
		for (int j = i; j < 30; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];	// dp[i][j] 는 왼쪽 위 값 + 왼쪽 값
	for (int i = 0; i < T; ++i) {
		int N, M;
		cin >> N >> M;
		cout << dp[N][M] << '\n';
	}
	return 0;
}
