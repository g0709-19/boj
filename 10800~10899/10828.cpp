#include <iostream>
#include <string>

using namespace std;

typedef int TYPE;

class Stack {
private:
	TYPE *data;
public:
	int _top;
	Stack() {
		_top = -1;
		data = new TYPE[10000];
	}
	void push(TYPE data);
	void pop();
	void size();
	void empty();
	void top();
};

void Stack::push(TYPE data) {
	this->data[++_top] = data;
}

void Stack::pop() {
	if (_top == -1)
		cout << -1 << '\n';
	else
		cout << this->data[_top--] << '\n';
}

void Stack::size() {
	cout << _top + 1 << '\n';
}

void Stack::empty() {
	cout << (_top == -1 ? 1 : 0) << '\n';
}

void Stack::top() {
	if (_top == -1)
		cout << -1 << '\n';
	else
		cout << this->data[_top] << '\n';
}

int main() {
	int command;
	cin >> command;
	Stack stack;
	for (int i=0; i<command; ++i) {
		string c;
		cin >> c;
		if (c.compare("push") == 0) {
			TYPE data;
			cin >> data;
			stack.push(data);
		}
		else if (c.compare("pop") == 0) {
			stack.pop();
		}
		else if (c.compare("size") == 0) {
			stack.size();
		}
		else if (c.compare("empty") == 0) {
			stack.empty();
		}
		else if (c.compare("top") == 0) {
			stack.top();
		}
	}
	return 0;
}
