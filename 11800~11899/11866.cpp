#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	int arr[1001] = { 0, };
	for (int i = 1; i <= N; ++i)
		arr[i - 1] = i;

	int index = 0, count = 0;
	for (int i = 0; i < N; i = (i + 1) % N) {
		if (arr[i] == 0) continue;
		if (++index % K == 0) {
			q.push(arr[i]);
			arr[i] = 0;
			if (++count == N) break;
		}
	}

	cout << "<";
	while (q.empty() == 0) {
		cout << q.front();
		q.pop();
		if (q.empty() == 0)
			cout << ", ";
	}
	cout << ">\n";
	return 0;
}
