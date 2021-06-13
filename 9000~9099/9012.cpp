#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		stack<int> stack;
		bool check = true;
		for (int i = 0, l = s.length(); i < l; ++i) {
			if (s[i] == '(') {
				stack.push('(');
			}
			else if (s[i] == ')') {
				if (stack.empty()) {
					cout << "NO\n";
					check = false;
					break;
				}
				stack.pop();
			}
		}
		if (!stack.empty()) cout << "NO\n";
		else if (check) cout << "YES\n";
	}
	return 0;
}
