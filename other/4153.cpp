#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num[3] = { 0, };
	while (1) {
		cin >> num[0] >> num[1] >> num[2];
		if (num[0] == 0 && num[1]== 0 && num[2] == 0) break;
		
		int _max = max(max(num[0], num[1]), num[2]);
		int left = 0;
		for (int i = 0; i < 3; ++i) {
			if (num[i] == _max) continue;
			left += num[i] * num[i];
		}

		if (_max * _max == left)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}
