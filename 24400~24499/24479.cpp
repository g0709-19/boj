#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

int count = 0;
vector<int> order;
vector<bool> visited;

void dfs(vector<vector<int>> &edges, int visit) {
  if (!visited[visit]) {
    visited[visit] = 1;
    order[visit] = ++count; // 방문하는대로 X 해당 정점의 방문 순서를 출력하는 문제
    sort(edges[visit].begin(), edges[visit].end());
    for (int to : edges[visit]) {
      dfs(edges, to);
    }
  }
}

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  order = vector<int>(N+1, 0);
  visited = vector<bool>(N+1);
  vector<vector<int>> edges(N+1, vector<int>());
  for (int i=0; i<M; ++i) {
    int from, to;
    cin >> from >> to;
    edges[from].push_back(to);
    edges[to].push_back(from); // 무방향 그래프 유의
  }
  dfs(edges, R);
  for (int i=1; i<=N; ++i) {
    cout << order[i] << '\n';
  }
  return 0;
}