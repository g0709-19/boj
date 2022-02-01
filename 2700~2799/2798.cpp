#include <iostream>
#include <vector>
#include <algorithm>

#define VISITED -1

using std::cout;
using std::cin;
using std::vector;
using std::max;

int answer = 0;
int N = 0, M = 0;

// 1. 방문 검사 필요 없었다. (=> start index 를 쌓는 방식... 순서에 상관없이 뽑기 때문에 가능)
// 2. n이 0일 때는 카드를 뽑을 필요가 없었다.

void solve(vector<int> &source, vector<int> &empty, int n, int start) {
  // Calculate max if all cards chose
  if (n == 0) {
    int sum = 0;
    for (int i=0; i<empty.size(); ++i) {
      sum += empty[i];
    }
    if (sum <= M) {
      answer = max(answer, sum);
    }
  } else {
    // Choose a card can be chose
    for (int i=start; i<N; ++i) {
      int choose = source[i];
      empty.push_back(choose);

      solve(source, empty, n-1, i+1);

      empty.pop_back();
    }
  }
}

int main() {
  cin >> N >> M;
  vector<int> source(N);
  for (int i=0; i<N; ++i) {
    cin >> source[i];
  }
  vector<int> empty;
  solve(source, empty, 3, 0);
  cout << answer << '\n';
  return 0;
}