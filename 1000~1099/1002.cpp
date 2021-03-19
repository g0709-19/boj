#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int x[2], y[2], r[2];
		cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
		int d = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
		int sum = (r[0] + r[1]) * (r[0] + r[1]);
		int dif = (r[0] - r[1]) * (r[0] - r[1]);
		if (d == 0) {
			if (dif == 0)
				cout << "-1\n";
			else
				cout << "0\n";
		}
		else if (d == sum || d == dif)
			cout << "1\n";
		else if (d < sum && d > dif)
			cout << "2\n";
		else
			cout << "0\n";
	}
	return 0;
}
