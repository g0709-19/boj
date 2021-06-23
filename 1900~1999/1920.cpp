#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int binary_search(vector<ll>& v, ll& key, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (key < v[mid])
		return binary_search(v, key, start, mid - 1);
	else if (v[mid] < key)
		return binary_search(v, key, mid + 1, end);
	else
		return v[mid];
}

void swap(ll& a, ll& b) {
	ll temp;
	temp = a;
	a = b;
	b = temp;
}

void quick_sort(vector<ll>& v, int left, int right) {
	if (left < right) {
		int pivot = left;
		int i = left + 1;
		int j = right;
		do {
			for (; i <= right; ++i) {
				if (v[i] > v[pivot]) break;
			}
			for (; left < j; --j) {
				if (v[j] < v[pivot]) break;
			}
			if (i < j)
				swap(v[i], v[j]);
		} while (i < j);
		swap(v[pivot], v[j]);
		quick_sort(v, left, j - 1);
		quick_sort(v, j + 1, right);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	quick_sort(v, 0, n - 1);

	int m;
	cin >> m;
	while (m--) {
		ll key;
		cin >> key;
		int location = binary_search(v, key, 0, n - 1);
		if (location == -1)
			cout << "0\n";
		else
			cout << "1\n";
	}
	return 0;
}
