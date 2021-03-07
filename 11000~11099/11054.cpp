#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	vector<int> S(N + 2);
	S[N + 1] = 0;

	for (int i = 1; i <= N; ++i) {
		cin >> S[i];
	}

	vector<int> dp(N + 1);
	vector<int> dp2(N + 1);

	int answer = 0;

	for (int i = 1; i <= N; ++i) {
		int upper, lower;
		upper = lower = 0;
		for (int j = 0; j < i; ++j) {
			if (S[j] < S[i])
				upper = max(upper, dp[j]);
			if (S[N+1-j] < S[N+1-i])
				lower = max(lower, dp2[j]);
		}

		dp[i] = upper + 1;
		dp2[i] = lower + 1;
	}

	for (int i = 1; i <= N; ++i) {
		answer = max(answer, dp[i] + dp2[N + 1 - i]);
	}

	cout << answer - 1 << '\n';
	return 0;
}
