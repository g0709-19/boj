#include <iostream>
#include <vector>

#define DIV		1000000000

using namespace std;

vector<vector<long long>> dp;

long long stair(int n, int last) {
	if (n == 1) return 1;
	long long &v = dp[n][last];
	if (v) return v;
	if (last == 9) return v = stair(n-1, last-1) % DIV;
	if (last == 0) return v = stair(n-1, last+1) % DIV;
	return v = (stair(n-1, last-1)%DIV + stair(n-1, last+1)%DIV) % DIV;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	dp = vector<vector<long long>>(N+1);
	for (int i=1; i<=N; ++i)
		dp[i] = vector<long long>(10);

	long long answer = 0;
	for (int i=1; i<=9; ++i) {
		answer += stair(N, i);
	}
	cout << answer%DIV << '\n';
	return 0;
}
