#include <iostream>
#include <vector>

using namespace std;

int prime[10001] = { 0, 1, };	// 0이면 소수

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i < 10000; ++i)
		for (int j = i * i; j < 10000; j = j + i)
			prime[j] = 1;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool first = true;
		pair<int, int> p(0, 0);
		for (int i = 0; i <= n / 2; ++i) {
			int f = n / 2 - i;
			int b = n / 2 + i;
			// 둘다 소수라면
			if (prime[f] == 0 && prime[b] == 0) {
				// 두 소수의 차가 가장 작은 것을 저장
				if (first || (p.second - p.first > b - f)) {
					first = false;
					p.first = f;
					p.second = b;
				}
			}
		}
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}
