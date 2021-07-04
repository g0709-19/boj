#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int>> graph;

void bfs(graph& g, int v_size, int e_size, int start, int condition) {
	vector<int> distance(v_size);
	queue<int> q;

	q.push(start);
	while (!q.empty()) {
		int visit = q.front();
		q.pop();

		int start = 0;
		int end = e_size;
		int lower, upper;
		
		// lower bound
		while (start <= end) {
			int mid = (start + end) / 2;
			if (mid >= e_size) break;	// start == end == mid == e_size 면 종료
			if (visit <= g[mid].first) end = mid - 1;
			else start = mid + 1;
		}
		lower = start;

		start = 0, end = e_size;
		// upper bound
		while (start <= end) {
			int mid = (start + end) / 2;
			if (mid >= e_size) break;	// start == end == mid == e_size 면 종료
			if (g[mid].first <= visit) start = mid + 1;
			else end = mid - 1;
		}
		upper = start;

		// visit 이 방문할 수 있는 점들만 탐색
		for (int i = lower; i < upper; ++i) {
			int to = g[i].second;
			if (distance[to] == 0) {
				distance[to] = distance[visit] + 1;
				q.push(to);
			}
		}
	}
	
	distance[start] = 0;	// X에서 X까지의 최단 거리는 무조건 0
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < v_size; ++i) {
		if (distance[i] != condition) continue;
		pq.push(i);	// 오름차순으로 출력
	}

	if (pq.size() == 0)
		cout << "-1\n";
	else while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	graph g;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		g.push_back({ a, b });
	}
	sort(g.begin(), g.end());	// 이분 탐색을 위해 정렬
	bfs(g, N + 1, M, X, K);
	return 0;
}
