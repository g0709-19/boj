#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using house = vector<vector<bool>>;

int main() {
  int n;
  cin >> n;
  house h(n, vector<bool>(n, false));
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      char temp;
      cin >> temp;
      h[i][j] = temp == '1';
      // char 로 받아서 1이 '1' 인 것을 생각을 못 했다.
    }
  }

  // 1. 방문하지 않은 1을 찾는다
  house visited(n, vector<bool>(n, false));
  vector<int> danji;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (!visited[i][j] && h[i][j] == 1) {
        int apart = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
          auto adj = q.front();
          q.pop();
          // 1 조건 검사를 안 넣었었다.
          if (!visited[adj.first][adj.second] && h[adj.first][adj.second] == 1) {
            visited[adj.first][adj.second] = true;
            ++apart;
            
            // 2. 그 1을 기점으로 상하좌우를 방문한다.
            if (adj.first-1 >= 0) {
              q.push({adj.first-1, adj.second});
            }
            if (adj.first+1 < n) {
              q.push({adj.first+1, adj.second});
            }
            if (adj.second-1 >= 0) {
              q.push({adj.first, adj.second-1});
            }
            if (adj.second+1 < n) {
              q.push({adj.first, adj.second+1});
            }
          }
        }
        danji.push_back(apart);
      }
    }
  }
  
  cout << danji.size() << '\n';
  sort(danji.begin(), danji.end());
  for (auto a : danji) {
    cout << a << '\n';
  }
  return 0;
}