#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;
	cin >> A >> B;

	A = '0' + A;
	B = '0' + B;

	int len_a = A.length();
	int len_b = B.length();
	
	vector<vector<int>> dp(len_a);
	dp[0] = vector<int>(len_b);

	for (int i = 1; i < len_a; ++i) {
		dp[i] = vector<int>(len_b);
		for (int j = 1; j < len_b; ++j) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[len_a - 1][len_b - 1] << '\n';
	return 0;
}
