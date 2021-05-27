#include <iostream>
#include <vector>

#define MOD	1000000007

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator * (const matrix& a, matrix& b) {
	ll size_a = a.size();
	ll size_b = b[0].size();
	matrix result(size_a, vector<ll>(size_b));	// 2차원 벡터 초기화
	for (ll i = 0; i < size_a; ++i) {
		for (ll j = 0; j < size_b; ++j) {
			for (ll k = 0; k < size_a; ++k) {
				result[i][j] += a[i][k] * b[k][j];	// 행렬 곱
			}
			result[i][j] %= MOD;
		}
	}
	return result;
}

matrix power(matrix a, ll n) {
	ll size = a.size();
	matrix result(size, vector<ll>(size));
	for (ll i = 0; i < size; ++i)
		result[i][i] = 1;
	while (n) {
		if (n % 2 == 0) {	// 짝수면 a^2^n/2 형태로 바꿈
			a = a * a;
			n /= 2;
		}
		else {				// 홀수면 a * a^n-1 형태로 바꿈
			result = result * a;
			--n;
		}
	}
	return result;
}

ll fibonacci(ll n) {
	matrix temp = { {1,1}, {1,0} };	// 제곱할 행렬
	--n;
	temp = power(temp, n);
	return (temp[1][0] + temp[1][1]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	cout << fibonacci(n) << '\n';
	return 0;
}
