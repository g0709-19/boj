#include <iostream>

using namespace std;

bool isPrimeNumber(int& n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int M, N;
	cin >> M >> N;
	int sum = 0;
	int min = 0;
	for (int i = M; i <= N; ++i) {
		if (isPrimeNumber(i)) {
			sum += i;
			if (min == 0)
				min = i;
		}
	}
	if (sum == 0)
		cout << "-1\n";
	else
		cout << sum << '\n' << min << '\n';
	return 0;
}
