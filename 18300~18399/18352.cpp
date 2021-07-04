#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> graph;

void bfs(graph& g, int size, int start, int condition) {
	vector<int> distance(size);
	queue<int> q;

	q.push(start);
	while (!q.empty()) {
		int visit = q.front();
		q.pop();
		int e_size = g[visit].size();
		for (int e = 0; e < e_size; ++e) {
			if (distance[g[visit][e]] == 0) {
				distance[g[visit][e]] = distance[visit] + 1;
				q.push(g[visit][e]);	// 방문하지 않은 정점만 큐에 삽입
			}
		}
	}

	distance[start] = 0;	// X 에서 X 까지의 최단 거리는 무조건 0
	vector<int> answer;
	for (int i = 0; i < size; ++i) {
		if (distance[i] != condition) continue;
		answer.push_back(i);
	}
	int count = answer.size();
	sort(answer.begin(), answer.end());	// 정답은 오름차순으로 출력
	if (count == 0)
		cout << "-1\n";
	else for (int i = 0; i < count; ++i)
		cout << answer[i] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	graph g(N + 1, vector<int>());
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	bfs(g, N + 1, X, K);
	return 0;
}
