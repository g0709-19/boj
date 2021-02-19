#include <iostream>
#include <vector>

#define MAX		9	// 9�� 9��

using namespace std;

int arr[MAX][MAX] = { 0, };

typedef struct Point {
	int x;
	int y;
	Point() : x(-1), y(-1) {}
	Point(int x, int y) : x(x), y(y) {}
} Point;

// ������ �湮�� ��ġ
Point next() {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			if (arr[i][j] == 0)
				return Point(i, j);
	return Point(-1, -1);
}

// ���� ��ǥ���� Ȯ��
bool empty(Point& p) { return p.x == -1 && p.y == -1; }

// �� ��ǥ�� ���� �� �ִ� ���� ������ ����
vector<int> most(Point& p) {
	bool check[MAX + 1] = { 0, };
	// y�� �˻�
	for (int i = 0; i < MAX; ++i)
		if (!check[arr[i][p.y]])
			check[arr[i][p.y]] = true;
	// x�� �˻�
	for (int i = 0; i < MAX; ++i)
		if (!check[arr[p.x][i]])
			check[arr[p.x][i]] = true;
	// 3x3 ���簢�� �˻�
	for (int i = (p.x / 3) * 3; i < (p.x / 3) * 3 + 3; ++i)
		for (int j = (p.y / 3) * 3; j < (p.y / 3) * 3 + 3; ++j)
			if (!check[arr[i][j]])
				check[arr[i][j]] = true;
	// ������ ���� ��ȯ
	vector<int> v;
	for (int i = 1; i <= MAX; ++i)
		if (!check[i]) v.push_back(i);
	// v�� ����ִٸ� ������ ���ڰ� ���� ��
	return v;
}

bool clear = false;
void sudoku() {
	if (clear) return;
	// ����ִ� ĭ ��� �湮
	Point p;
	while (!empty(p = next())) {
		vector<int> v = most(p);
		// �� ��ǥ�� ���� ������ ���ڰ� �ִٸ� �����ϰ� ���� ��ǥ �湮
		if (!v.empty()) {
			int i;
			int size = v.size();
			for (i = 0; i < size; ++i) {
				arr[p.x][p.y] = v[i];
				// ���� ä����
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
			if (i == size) return;	// ������ ���ڰ� ���ٸ� �� �ܰ�� backtracking
		}
		else // ������ ���ڰ� ���ٸ� �� �ܰ�� backtracking
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cin >> arr[i][j];
		}
	}

	sudoku();

	// ���
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}