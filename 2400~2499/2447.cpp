#include <iostream>

using namespace std;

void star(int n, int i, int j) {
	if (i % 3 == 1 && j % 3 == 1) {
		cout << ' ';
	}
	else {
		if (n / 3 > 0)
			star(n / 3, i / 3, j / 3);
		else
			cout << '*';
	}
}

int main()
{
	int N;
	cin >> N;
	// NxN 좌표를 모두 검사해서 해당 좌표에 무슨 문자가 들어가는지 결정
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			star(N, i, j);
		}
		cout << '\n';
	}
	return 0;
}
