#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void solve(vector<int> &v, int n) {
  // 인접한 동일한 수열 검사
  bool isEqual = false;
  for (int c=1, size=v.size(); c<=size/2; ++c) {
    isEqual = true;
    // c 길이 수열의 모든 숫자가 일치했을 때 동일한 수열임
    for (int i=1; i<=c; ++i) {
      isEqual &= v[size-i] == v[size-c-i];
    }
    if (isEqual) {
      break;
    }
  }

  if (!isEqual) {
    if (n == 0) {
      for (int i : v) {
        cout << i;
      }
      cout << '\n';
      exit(0);
    } else {
      for (int i=1; i<=3; ++i) {
        v.push_back(i);
        solve(v, n-1);
        v.pop_back();
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v;
  solve(v, n);
}