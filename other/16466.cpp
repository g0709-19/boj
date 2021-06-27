#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ll> v(n);
	int max_value = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (max_value < v[i])
			max_value = v[i];
	}
	vector<bool> v2(max_value + 1);
	for (int i = 0; i < n; ++i) v2[v[i]] = 1;
	int answer = 1;
	while (answer <= max_value && v2[answer] != 0) ++answer;
	cout << answer << '\n';
	return 0;
}
