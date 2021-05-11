#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		char s[102];
		cin.getline(s, 102);
		if (strcmp(s, ".") == 0)
			break;
		stack<int> stack;
		bool check = true;
		for (char* c = s; *c != 0; ++c) {
			if (*c == '(' || *c == '[') {
				stack.push(*c);
			}
			else if (*c == ')' || *c == ']') {
				if (stack.empty() ||
				(*c == ')' && stack.top() != '(') ||
				(*c == ']' && stack.top() != '[')) {
					cout << "no\n";
					check = false;
					break;
				}
				stack.pop();
			}
		}
		if (!stack.empty() && check) cout << "no\n";
		else if (check) cout << "yes\n";
	}
	return 0;
}
