#include <iostream>

using namespace std;

int white = 0;
int blue = 0;

void partition(int paper[][129], int row, int column, int size) {
	int temp = paper[row][column];	// 1이면 blue
	for (int i = row; i < row + size; ++i)
		for (int j = column; j < column + size; ++j)
			if (paper[i][j] != temp) {	// 하나라도 같지 않은 색 있으면 break
				temp = -1;
				break;
			}
	if (temp == 1) ++blue;			// 다 같은 색이면 카운트
	else if (temp == 0) ++white;
	else {	// 같은 색 아니면 4분할
		partition(paper, row, column, size / 2);
		partition(paper, row + size / 2, column, size / 2);
		partition(paper, row, column + size / 2, size / 2);
		partition(paper, row + size / 2, column + size / 2, size / 2);
	}
}

int main() {
	int N;
	int paper[129][129];
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];
	partition(paper, 0, 0, N);
	cout << white << '\n' << blue << '\n';
}
