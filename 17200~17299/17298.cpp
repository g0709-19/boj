#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> answer(N);
	for (int i = 0; i < N; ++i) answer[i] = -1;
	stack<int> s;

	cin >> v[0];
	s.push(0);	// 인덱스가 들어감

	for (int i = 1; i < N; ++i) {
		cin >> v[i];
		while (s.empty() == 0 && v[s.top()] < v[i]) {
			answer[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; ++i) cout << answer[i] << " ";
	cout << '\n';
	return 0;
}
