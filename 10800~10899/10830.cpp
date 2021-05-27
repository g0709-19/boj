#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator * (const matrix &a, matrix &b) {
	ll size = a.size();
	matrix result(size, vector<ll>(size));	// 2차원 벡터 초기화
	for (ll i = 0; i < size; ++i) {
		for (ll j = 0; j < size; ++j) {
			for (ll k = 0; k < size; ++k) {
				result[i][j] += a[i][k] * b[k][j];	// 행렬 곱
			}
			result[i][j] %= 1000;	// 문제에서 1000으로 나눈 나머지라 명시함
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N, B;
	cin >> N >> B;
	matrix A(N, vector<ll>(N));
	for (ll i = 0; i < N; ++i) {
		for (ll j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	
	matrix result = power(A, B);

	for (ll i = 0; i < N; ++i) {
		for (ll j = 0; j < N; ++j) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
