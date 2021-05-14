#include <iostream>

using namespace std;

typedef int	DATA;

class Queue {
private:
	int _front, _rear;
public:
	DATA data[2000000] = { 0, };
	Queue() { _front = -1; _rear = -1; }
	void push(DATA d);
	void pop();
	void size();
	void empty();
	void front();
	void back();
};

void Queue::push(DATA d) {
	data[++_rear] = d;
}

void Queue::pop() {
	if (_front == _rear) cout << "-1\n";
	else cout << data[++_front] << '\n';
}

void Queue::size() {
	if (_front == _rear) cout << "0\n";
	else cout << _rear - _front << '\n';
}

void Queue::empty() {
	if (_front == _rear) cout << "1\n";
	else cout << "0\n";
}

void Queue::front() {
	if (_front == _rear) cout << "-1\n";
	else cout << data[_front+1] << '\n';
}

void Queue::back() {
	if (_front == _rear) cout << "-1\n";
	else cout << data[_rear] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int command;
	cin >> command;
	Queue queue;
	for (int i = 0; i < command; ++i) {
		string c;
		cin >> c;
		if (c.compare("push") == 0) {
			DATA data;
			cin >> data;
			queue.push(data);
		}
		else if (c.compare("pop") == 0) {
			queue.pop();
		}
		else if (c.compare("size") == 0) {
			queue.size();

