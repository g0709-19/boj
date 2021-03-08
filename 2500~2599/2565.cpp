#include <iostream>
#include <vector>
#include <algorithm>

#define VALUE	1

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> G(N+1);

	for (int i = 1; i <= N; ++i) {
		vector<int> temp(2);
		cin >> temp[0] >> temp[VALUE];
		G[i] = temp;
	}

	// 정렬 중요
	sort(G.begin(), G.end());

	int answer = 0;
	vector<int> dp(N+1);

	// 전체 길이에서 LIS 길이를 뺌
	for (int i = 1; i <= N; ++i) {
		int temp = 0;
		for (int j = 0; j < i; ++j) {
			if ((G[j].size() > 0 ? G[j][VALUE] : 0) < G[i][VALUE])
				temp = max(temp, dp[j]);
		}
		dp[i] = temp + 1;
		answer = max(answer, dp[i]);
	}

	cout << N - answer << '\n';
	return 0;
}
