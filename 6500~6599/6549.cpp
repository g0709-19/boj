#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> v;
vector<ll> tree;

void Init(int node, int start, int end) {
	if (start == end)
		tree[node] = start;	// 최소값의 인덱스
	else {
		int mid = (start + end) / 2;
		int l = node * 2, r = node * 2 + 1;
		Init(l, start, mid);
		Init(r, mid + 1, end);
		if (v[tree[l]] <= v[tree[r]])
			tree[node] = tree[l];
		else
			tree[node] = tree[r];
	}
}

int Shortest(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	int l = Shortest(node * 2, start, mid, left, right);
	int r = Shortest(node * 2 + 1, mid + 1, end, left, right);
	if (l == -1) return r;
	else if (r == -1) return l;
	else {
		if (v[l] <= v[r]) return l;
		else return r;
	}
}

ll Biggest(int& size, int start, int end) {
	int shortest = Shortest(1, 0, size - 1, start, end);	// 그 범위에서 가장 작은 높이의 인덱스
	ll area = (ll)(end - start + 1) * (ll)v[shortest];		// 직사각형의 넓이
	if (shortest - 1 >= start) {
		ll temp = Biggest(size, start, shortest - 1);
		if (temp > area) area = temp;
	}
	if (shortest + 1 <= end) {
		ll temp = Biggest(size, shortest + 1, end);
		if (temp > area) area = temp;
	}
	return area;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		v = vector<ll>(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int h = (int)ceil(log2(n)); int tree_size = (1 << (h + 1));
		tree = vector<ll>(tree_size);
		Init(1, 0, n - 1);
		cout << Biggest(n, 0, n - 1) << '\n';
	}
	return 0;
}
