#include <iostream>
#define MAX	2188

using namespace std;

int minus_one = 0;
int zero = 0;
int one = 0;

bool check(int paper[][MAX], int row, int column, int size) {
	for (int i = row; i < row + size; ++i)
		for (int j = column; j < column + size; ++j)
			// 하나라도 같지 않은 색 있으면 break
			if (paper[i][j] != paper[row][column])
				return false;
	return true;
}

void partition(int paper[][MAX], int row, int column, int size) {
	if (check(paper, row, column, size)) {	// 같은 색인지 체크
		if (paper[row][column] == -1) ++minus_one;
		else if (paper[row][column] == 0) ++zero;
		else if (paper[row][column] == 1) ++one;
	}
	else {	// 같은 색 아니면 9분할
		size /= 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				partition(paper, row + i * size, column + j * size, size);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	int paper[MAX][MAX];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];
	partition(paper, 0, 0, N);
	cout << minus_one << '\n' << zero << '\n' << one << '\n';
	return 0;
}
