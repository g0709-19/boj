#include <iostream>

using namespace std;

long long m[1000000] = { 0, };

long long tile(int n) {
	if (n == 0 || n == 1)
		return 1;
	long long &result = m[n];
	if (result)
		return result;
	else
		return result = (tile(n - 1) + tile(n - 2)) % 15746;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	cout << tile(N) % 15746L << '\n';
	return 0;
}
