#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<bool>> graph;

vector<bool> visited;

void reset(int size) {
	visited = vector<bool>(size);
}

void dfs(graph &g, int size, int start) {
	// 갈 수 있는 길이 있으면 방문
	// 방문했는지 검사
	// 방문 안 했으면 방문
	// 방문 끝나면 돌아감
	visited[start] = true;
	cout << start << " ";
	// 정점 번호를 1부터 매겨서 1 ~ size 전까지
	for (int i = 1; i < size; ++i) {
		// start 로 부터 i 로 가는 경로가 있고, 방문하지 않았던 정점이라면 방문
		if (g[start][i] && !visited[i]) {
			dfs(g, size, i);
		}
	}
}

void bfs(graph& g, int size, int start) {
	// start 와 인접한 정점 모두 큐에 삽입
	// 큐에 들어온 순서대로 꺼내서 방문
	queue<int> q;
	q.push(start);
	do {
		int vertex = q.front();
		q.pop();
		if (visited[vertex]) continue;
		visited[vertex] = true;
		cout << vertex << " ";
		for (int i = 1; i < size; ++i) {
			// 인접해있고 방문하지 않았다면 큐에 삽입
			if (g[vertex][i] && !visited[i])
				q.push(i);
		}
	} while (!q.empty());
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, v;
	cin >> n >> m >> v;
	graph g(n + 1, vector<bool>(n + 1));
	reset(n + 1);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1][v2] = true;
		g[v2][v1] = true;
	}
	dfs(g, n + 1, v); cout << "\n";
	reset(n + 1);
	bfs(g, n + 1, v); cout << "\n";
	return 0;
}
