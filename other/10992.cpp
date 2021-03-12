#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < N; ++i)
		cout << ' ';
	cout << "*\n";

	if (N > 2) {
		for (int i = 1; i <= N-2; ++i) {
			for (int j = 1; j < N - i; ++j)
				cout << ' ';
			cout << '*';
			for (int j = 0; j < 2 * i - 1; ++j)
				cout << ' ';
			cout << '*';
			cout << '\n';
		}
	}

	if (N > 1)
		for (int i = 0; i < N * 2 - 1; ++i)
			cout << '*';
	cout << '\n';
	return 0;
}
