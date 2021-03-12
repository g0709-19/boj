#include <iostream>

using namespace std;

enum date {
	SUN, MON, TUE, WED, THU, FRI, SAT
};

int main() {
	int x, y;
	cin >> x >> y;
	int day[13] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	for (int i = 1; i < x; ++i) {
		y += day[i];
	}
	switch (y % 7) {
	case SUN:
		cout << "SUN";
		break;
	case MON:
		cout << "MON";
		break;
	case TUE:
		cout << "TUE";
		break;
	case WED:
		cout << "WED";
		break;
	case THU:
		cout << "THU";
		break;
	case FRI:
		cout << "FRI";
		break;
	case SAT:
		cout << "SAT";
		break;
	}
	cout << '\n';
	return 0;
}
