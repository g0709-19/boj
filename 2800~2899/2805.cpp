#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll parametric_search(vector<ll> &tree, int condition, ll start, ll end) {
	while (start <= end) {
		ll height = (start + end) / 2;
		ll sum = 0;
		for (int i = 0, size = tree.size(); i < size; ++i) {
			if (tree[i] >= height)
				sum += tree[i] - height;
		}
		if (sum < condition) end = height - 1;
		else start = height + 1;
	}
	return end;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> tree(n);
	ll highest = 0;
	for (int i = 0; i < n; ++i) {
		cin >> tree[i];
		if (highest < tree[i])
			highest = tree[i];
	}
	cout << parametric_search(tree, m, 0, highest) << '\n';
}
