#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		queue<pair<int, int>> q;	// 우선순위, 책번호
		priority_queue<int> pq;		// 우선순위만 저장
		for (int i = 0; i < N; ++i) {
			int priority;
			cin >> priority;
			q.push({ priority, i });
			pq.push(priority);
		}
		int count = 0;
		while (q.empty() == 0) {
			// 가장 앞에 있는 문서의 중요도가 가장 높은 우선순위를 가지는가?
			if (q.front().first == pq.top()) {
				++count;	// 출력 시 횟수를 센다
				if (q.front().second == M) {
					cout << count << '\n';
					break;
				}
				q.pop(); pq.pop();
			}
			else {
				pair<int, int> temp = q.front();
				q.pop();
				q.push(temp);
			}
		}
	}
	return 0;
}
