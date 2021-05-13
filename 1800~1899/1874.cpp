#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	stack<int> s;
	queue<int> q;
	string answer = "";
	for (int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		s.push(i);
		q.push(c);
		answer += "+\n";
		while ((s.empty() == 0 && q.empty() == 0) && s.top() == q.front()) {
			answer += "-\n";
			s.pop();
			q.pop();
		}
	}
	if (s.empty() && q.empty())
		cout << answer;
	else
		cout << "NO\n";
	return 0;
}
