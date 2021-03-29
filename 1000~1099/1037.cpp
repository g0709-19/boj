#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << v[0] * v[n - 1] << '\n';
	return 0;
}
