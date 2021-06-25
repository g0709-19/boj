#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int k, n;
	cin >> k >> n;
	vector<ll> v(k);
	ll max_value = 0;
	for (int i = 0; i < k; ++i) {
		cin >> v[i];
		if (v[i] > max_value) max_value = v[i];
	}

	ll start = 1, end = max_value;
	ll mid;
	ll amount;

	do {
		amount = 0;
		mid = (start + end) / 2;
		// mid 로 만들 수 있는 선 개수 계산
		for (int i = 0; i < k; ++i)
			amount += v[i] / mid;

		// Parametric Search
		if (amount < n) end = mid - 1;
		else start = mid + 1;
	} while (start <= end);
	
	cout << end << '\n';
	return 0;
}
