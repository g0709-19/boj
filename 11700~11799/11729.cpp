#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 0) return;
	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int N;
	cin >> N;
	cout << (1<<N) - 1 << "\n";	// 2의 N제곱
	hanoi(N, 1, 2, 3);
}
