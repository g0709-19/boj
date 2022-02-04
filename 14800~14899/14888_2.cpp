#include <iostream>
#include <vector>
#include <algorithm>

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

using std::cout;
using std::cin;
using std::vector;
using std::max;
using std::min;

struct Info {
  int max_ = -123456789;
  int min_ = 123456789;
};
Info info;

int n;

// Bottom up => 우측 결합으로 원하던 결과가 안 나옴

void solve(const vector<int>& A, int op[4], const int lastOp, int lastResult, const int index) {
  // 앞에서부터 계산
  switch (lastOp) {
    case PLUS:     lastResult += A[index]; break;
    case MINUS:    lastResult -= A[index]; break;
    case MULTIPLY: lastResult *= A[index]; break;
    case DIVIDE:   lastResult /= A[index]; break;
    default: break;
  }

  // 마지막 숫자라면 최대값, 최소값 계산
  if (index == n - 1) {
    info.max_ = max(info.max_, lastResult);
    info.min_ = min(info.min_, lastResult);
  }

  // 다음 연산 수행
  for (int i=0; i<4; ++i) {
    if (op[i] != 0) {
      --op[i];
      solve(A, op, i, lastResult, index+1);
      ++op[i];
    }
  }
}

int main() {
  cin >> n;
  vector<int> A(n);
  for (int i=0; i<n; ++i) {
    cin >> A[i];
  }
  int op[4] = {0,};
  for (int i=0; i<4; ++i) {
    cin >> op[i];
  }
  solve(A, op, 0, 0, 0);
  cout << info.max_ << '\n';
  cout << info.min_ << '\n';
}