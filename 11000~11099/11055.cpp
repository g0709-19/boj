#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N+1);
	vector<int> dp(N+1);
	for (int i=1; i<=N; ++i) cin >> A[i];

	int answer = 0;
	for (int i=1; i<=N; ++i) {
		int temp = 0;
		for (int j=0; j<i; ++j) {
			if (A[j] < A[i])
				temp = max(temp, dp[j]);
		}
		dp[i] = temp + A[i];
		answer = max(answer, dp[i]);
	}
	cout << answer << '\n';
	return 0;
}
