#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> P(N);
	vector<int> m(N);
	for (int i = 0; i < N; ++i) cin >> P[i];
	sort(P.begin(), P.end());
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		m[i] = sum += P[i];
	}
	sum = 0;
	for (int i = 0; i < N; ++i)
		sum += m[i];
	cout << sum << '\n';
	return 0;
}
