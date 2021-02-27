#include <iostream>

#define MAX	100

using namespace std;

void solve(long long P[], int n) {
	for (int i = 3; i < n; ++i) {
		P[i] = P[i - 2] + P[i - 3];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	long long P[MAX] = { 1, 1, 1 };

	solve(P, MAX);

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		cout << P[N-1] << '\n';
	}
	return 0;
}
