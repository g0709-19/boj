#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	deque<int> dq;
	while (N--) {
		string command;
		cin >> command;
		if (command.compare("push_front") == 0) {
			int data;
			cin >> data;
			dq.push_front(data);
		}
		else if (command.compare("push_back") == 0) {
			int data;
			cin >> data;
			dq.push_back(data);
		}
		else if (command.compare("pop_front") == 0) {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command.compare("pop_back") == 0) {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (command.compare("size") == 0) {
			cout << dq.size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << dq.empty() << '\n';
		}
		else if (command.compare("front") == 0) {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << '\n';
		}
		else if (command.compare("back") == 0) {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << '\n';
		}
	}
	return 0;
}
