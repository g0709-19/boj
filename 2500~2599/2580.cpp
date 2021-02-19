#include <iostream>
#include <vector>

#define MAX		9	// 9행 9열

using namespace std;

int arr[MAX][MAX] = { 0, };

typedef struct Point {
	int x;
	int y;
	Point() : x(-1), y(-1) {}
	Point(int x, int y) : x(x), y(y) {}
} Point;

// 다음에 방문할 위치
Point next() {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			if (arr[i][j] == 0)
				return Point(i, j);
	return Point(-1, -1);
}

// 없는 좌표인지 확인
bool empty(Point& p) { return p.x == -1 && p.y == -1; }

// 그 좌표에 놓을 수 있는 가장 유력한 숫자
vector<int> most(Point& p) {
	bool check[MAX + 1] = { 0, };
	// y축 검사
	for (int i = 0; i < MAX; ++i)
		if (!check[arr[i][p.y]])
			check[arr[i][p.y]] = true;
	// x축 검사
	for (int i = 0; i < MAX; ++i)
		if (!check[arr[p.x][i]])
			check[arr[p.x][i]] = true;
	// 3x3 정사각형 검사
	for (int i = (p.x / 3) * 3; i < (p.x / 3) * 3 + 3; ++i)
		for (int j = (p.y / 3) * 3; j < (p.y / 3) * 3 + 3; ++j)
			if (!check[arr[i][j]])
				check[arr[i][j]] = true;
	// 유력한 숫자 반환
	vector<int> v;
	for (int i = 1; i <= MAX; ++i)
		if (!check[i]) v.push_back(i);
	// v가 비어있다면 유력한 숫자가 없는 것
	return v;
}

bool clear = false;
void sudoku() {
	if (clear) return;
	// 비어있는 칸 모두 방문
	Point p;
	while (!empty(p = next())) {
		vector<int> v = most(p);
		// 그 좌표에 놓을 유력한 숫자가 있다면 대입하고 다음 좌표 방문
		if (!v.empty()) {
			int i;
			int size = v.size();
			for (i = 0; i < size; ++i) {
				arr[p.x][p.y] = v[i];
				// 전부 채웠음
				{
					Point newp = next();
					if (empty(newp))
						clear = true;
				}
				sudoku();
				if (!clear)
					arr[p.x][p.y] = 0;
				else return;
			}
			if (i == size) return;	// 유력한 숫자가 없다면 전 단계로 backtracking
		}
		else // 유력한 숫자가 없다면 전 단계로 backtracking
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cin >> arr[i][j];
		}
	}

	sudoku();

	// 출력
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}