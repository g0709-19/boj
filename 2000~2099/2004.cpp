#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll count_zero2(ll n) {
	ll two = 0;
	for (ll i = 2; i <= n; i *= 2)
		two += n / i;
	return two;
}

ll count_zero5(ll n) {
	ll five = 0;
	for (ll i = 5; i <= n; i *= 5)
		five += n / i;
	return five;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m;
	cin >> n >> m;
	cout << min(count_zero2(n) - count_zero2(n - m) - count_zero2(m),
		count_zero5(n) - count_zero5(n - m) - count_zero5(m));
	return 0;
}
