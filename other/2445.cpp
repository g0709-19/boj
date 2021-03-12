#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j)
			cout << '*';
		for (int j = 0, k = N - i; j < 2 * k; ++j)
			cout << ' ';
		for (int j = 0; j < i; ++j)
			cout << '*';
		cout << '\n';
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = N - i; j > 0; --j)
			cout << '*';
		for (int j = 0; j < 2 * i; ++j)
			cout << ' ';
		for (int j = N - i; j > 0; --j)
			cout << '*';
		cout << '\n';
	}
	return 0;
}
