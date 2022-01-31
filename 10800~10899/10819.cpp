#include <iostream>
#include <vector>
#include <algorithm>

#define VISITED 1000

using std::cout;
using std::cin;
using std::vector;
using std::abs;
using std::max;

int answer = 0;

void solve(vector<int> &source, vector<int> &v, int n) {
  int size = source.size();
  if (n == 0) {
    int sum = 0;
    for (int i=size-1; i>=1; --i) {
      sum += abs(v[i-1] - v[i]);
    }
    answer = max(answer, sum);
  }
  
  for (int i=0; i<size; ++i) {
    int choose = source[i];
    if (choose != VISITED) {
      source[i] = VISITED;
      v.push_back(choose);
      
      solve(source, v, n - 1);
      
      source[i] = choose;
      v.pop_back();
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i=0; i<n; ++i) {
    cin >> v[i];
  }
  vector<int> empty;
  solve(v, empty, n);
  cout << answer << '\n';
  return 0;
}