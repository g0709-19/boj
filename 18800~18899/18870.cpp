#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<ll> origin(N);
	vector<ll> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		origin[i] = v[i];
	}
	sort(v.begin(), v.end());	// 오름차순 정렬
	v.erase(unique(v.begin(), v.end()), v.end());	// 중복된 값 제거
	for (int i = 0; i < origin.size(); ++i) {
		// 이진탐색하여 몇번째 숫자인지 매핑
		vector<ll>::iterator iter = lower_bound(v.begin(), v.end(), origin[i]);
		cout << iter - v.begin() << ' ';
	}
	cout << '\n';
	return 0;
}
