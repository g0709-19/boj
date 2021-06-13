#include <iostream>

using namespace std;

typedef long long ll;

int power(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	long long temp = power(a, b / 2, c);	// 10^10 이라면 10^5 * 10^5 로 계산
	if (b % 2 == 0) {
		return temp * temp % c;
	}
	else {
		return (temp * temp % c) * a % c;
	}
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C) % C << '\n';
	return 0;
}
