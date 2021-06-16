#include <iostream>

#define P	1000000007

using namespace std;

typedef long long ll;

ll factorial(ll n)
{
	ll result = 1;
	for (ll i = 2; i <= n; ++i)
	{
		result *= i;
		result %= P;
	}
	return result;
}

ll power(ll a, ll b) {
	if (b == 1) return a % P;
	ll temp = power(a, b / 2);
	if (b % 2 == 0) {
		return temp * temp % P;
	}
	else {
		return (temp * temp % P) * a % P;
	}
}

// 페르마의 소정리
// n! * (k! * (n-k)!)^p-2 % p = n! * (k! * (n-k)!)^-1 % p
ll combination(ll n, ll k)
{
	ll n_fac = 1;
	for (ll i = 2; i <= n; ++i)
	{
		n_fac *= i;
		n_fac %= P;
	}
	ll k_fac = 1;
	for (ll i = 2; i <= k; ++i)
	{
		k_fac *= i;
		k_fac %= P;
	}
	for (ll i = 2; i <= n-k; ++i)
	{
		k_fac *= i;
		k_fac %= P;
	}
	return n_fac * power(k_fac, P - 2) % P;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N, K;
	cin >> N >> K;
	cout << combination(N, K) << '\n';
	return 0;
}
