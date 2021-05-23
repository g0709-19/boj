#include <iostream>

using namespace std;

void partition(char paper[][129], int row, int column, int size) {
	int temp = paper[row][column];	// 1이면 black
	for (int i = row; i < row + size; ++i)
		for (int j = column; j < column + size; ++j)
			if (paper[i][j] != temp) {	// 하나라도 같지 않은 색 있으면 break
				temp = -1;
				break;
			}
	if (temp == -1) {	// 같은 색 아니면 4분할
		cout << '(';
		partition(paper, row, column, size / 2);
		partition(paper, row, column + size / 2, size / 2);
		partition(paper, row + size / 2, column, size / 2);
		partition(paper, row + size / 2, column + size / 2, size / 2);
		cout << ')';
	}
	else {
		cout << temp;
	}
}

int main() {
	int N;
	char paper[129][129];
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> paper[i][j];
			paper[i][j] -= '0';
		}

	partition(paper, 0, 0, N);
}
