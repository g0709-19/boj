#include <iostream>

#define MAX		9	// 1 ≤ M ≤ N ≤ 8

using namespace std;

int N, M;
int arr[MAX] = { 0, };

void solve(int depth, int last) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	// A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK
	for (int i = last - 1; i <= N; ++i) {
		arr[depth] = i;
		solve(depth + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	solve(0, 2);
	return 0;
}
