#include <iostream>

#define MAX		9

using namespace std;

int N, M;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void solve(int depth, int last) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = last; i <= N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i;
			solve(depth + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	solve(0, 1);
	return 0;
}
