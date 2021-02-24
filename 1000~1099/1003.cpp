#include <iostream>

#define MAX	40

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int f[MAX + 1] = { 0, 1, 1 };
	for (int i = 3; i <= MAX; ++i)
		f[i] = f[i - 1] + f[i - 2];
	
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;

		if (N == 0)
			cout << "1 0\n";
		else if (N == 1)
			cout << "0 1\n";
		else
			// 0의 개수는 1, 0, 1, 1, 2, 3, ...
			// 1의 개수는 0, 1, 1, 2, 3, 5, ...
			cout << f[N - 1] << " " << f[N] << '\n';
	}
	return 0;
}
