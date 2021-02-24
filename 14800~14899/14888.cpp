#include <iostream>
#include <cmath>

#define OPERATOR	4
#define INF			101

using namespace std;

int N;
int *A;
int ops[OPERATOR];	// 덧셈, 뺄셈, 곱셈, 나눗셈 순
int _max, _min;
int sum = 0;

void solve(int depth) {
	if (depth == N-1) {
		if (_max < sum || _max == INF)
			_max = sum;
		if (_min > sum || _min == INF)
			_min = sum;
		//cout << '\n';
		return;
	}

	for (int i=0; i<OPERATOR; ++i) {
		if (ops[i] > 0) {
			int temp_sum = sum;
			--ops[i];
			switch (i) {
			case 0:
				sum += A[depth+1];
				break;
			case 1:
				sum -= A[depth+1];
				break;
			case 2:
				sum *= A[depth+1];
				break;
			case 3:
				//cout << sum << " / " << A[depth+1] << " \n";
				if (sum < 0 && A[depth+1] > 0)
					sum = (abs(sum) / A[depth+1]) * -1;
				else
					sum /= A[depth+1];
				break;
			}
			//cout << i << " 방문 " << depth+1 << " " << sum << '\n';
			solve(depth + 1);
			//cout << "방문 종료\n";
			//sum = A[0];
			sum = temp_sum;
			++ops[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	A = new int[N];
	for (int i=0; i<N; ++i)
		cin >> A[i];
	for (int i=0; i<OPERATOR; ++i)
		cin >> ops[i];
	sum = A[0];
	_max = _min = INF;
	solve(0);
	cout << _max << '\n' << _min << '\n';
	delete[] A;
	return 0;
}
