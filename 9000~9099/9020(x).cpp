#include <iostream>
#include <vector>

using namespace std;

int prime[10001] = { 0, 1, };	// 0이면 소수
bool check = false;
vector<int> v;

int sum(vector<int> v) {
	int s = 0;
	for (int i = 0; i < v.size(); ++i)
		s += v[i];
	return s;
}

void find(int n, int last) {
	int s = sum(v);
	if (s == n) {
		check = true;
		return;
	}
	if (s > n) return;
	for (int i = last; i < n; ++i) {
		if (sum(v) == n) return;
		if (prime[i] != 0) continue;	// 소수 아니면 무시
		v.push_back(i);
		find(n, last + 1);
		if (!check)
			v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i < 10000; ++i)
		for (int j = i * i; j < 10000; j = j + i)
			prime[j] = 1;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		find(n, 2);
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << ' ';
		cout << '\n';
		check = false;
		v = vector<int>();
	}
	return 0;
}
