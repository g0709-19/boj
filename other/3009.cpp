#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x[3], y[3];
	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];
	sort(x, x + 3); sort(y, y + 3);
	if (x[0] == x[1]) {
		for (int i = 1; i < 3; ++i) {
			if (x[0] != x[i]) {
				cout << x[i] << ' ';
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 2; ++i) {
			if (x[i] != x[2]) {
				cout << x[i] << ' ';
				break;
			}
		}
	}
	if (y[0] == y[1]) {
		for (int i = 1; i < 3; ++i) {
			if (y[0] != y[i]) {
				cout << y[i] << ' ';
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 2; ++i) {
			if (y[i] != y[2]) {
				cout << y[i] << ' ';
				break;
			}
		}
	}
	cout << '\n';
	return 0;
}
