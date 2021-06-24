#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// 찾는 값 첫 번째
int lower_bound(vector<ll>& v, ll& key, int start, int end) {
	if (start > end) return start;
	int mid = (start + end) / 2;
	if (key <= v[mid])
		return lower_bound(v, key, start, mid - 1);
	else
		return lower_bound(v, key, mid + 1, end);
}

// 찾는 값 바로 다음으로 오는 큰 값
int upper_bound(vector<ll>& v, ll& key, int start, int end) {
	if (start > end) return start;
	int mid = (start + end) / 2;
	if (v[mid] <= key)
		return upper_bound(v, key, mid + 1, end);
	else
		return upper_bound(v, key, start, mid - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	int m;
	cin >> m;
	while (m--) {
		ll key;
		cin >> key;
		int lower_result = lower_bound(v, key, 0, n - 1);
		int upper_result = upper_bound(v, key, 0, n - 1);
		int count = upper_result - lower_result;
		//int count = upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key);
		cout << count << ' ';
	}
	return 0;
}
