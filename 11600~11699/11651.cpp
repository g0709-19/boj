#include <iostream>
#include <algorithm>

typedef struct Point {
	int x;
	int y;
} Point;

bool compare(Point i, Point j) {
	if (i.y == j.y)
		return i.x < j.x;
	return i.y < j.y;
}

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 입력
	Point *arr = new Point[n];
	for (int i=0; i<n; ++i) {
		cin >> arr[i].x >> arr[i].y;
	}

	// 정렬
	sort(arr, arr+n, compare);

	// 출력
	for (int i=0; i<n; ++i)
		cout << arr[i].x << " " << arr[i].y << '\n';
	
	delete[] arr;
	return 0;
}
