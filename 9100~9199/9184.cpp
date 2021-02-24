#include <iostream>
//#include <string>
//#include <sstream>

#define MIN	-50
#define MAX	50

using namespace std;

//int w(int a, int b, int c) {
//	if (a <= 0 || b <= 0 || c <= 0)
//		return 1;
//	if (a > 20 || b > 20 || c > 20)
//		return w(20, 20, 20);
//	if (a < b && b < c)
//		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
//}

void w(int arr[][MAX*2+1][MAX*2+1]) {
	for (int i = 0; i < 2; ++i) {
		for (int a = MIN; a <= MAX; ++a) {
			for (int b = MIN; b <= MAX; ++b) {
				for (int c = MIN; c <= MAX; ++c) {
					// a -> b -> c 순서로 하면 1 1 21 일 때
					// 20 20 20 의 값이 정해져 있지 않음
					int temp;
					if (a <= 0 || b <= 0 || c <= 0)
						temp = 1;
					else if (a > 20 || b > 20 || c > 20)
						temp = arr[20+MAX][20+MAX][20+MAX];
					else if (a < b && b < c)
						temp = arr[a + MAX][b + MAX][c - 1 + MAX] + arr[a + MAX][b - 1 + MAX][c - 1 + MAX] - arr[a + MAX][b - 1 + MAX][c + MAX];
					else
						temp = arr[a - 1 + MAX][b + MAX][c + MAX] + arr[a - 1 + MAX][b - 1 + MAX][c + MAX] + arr[a - 1 + MAX][b + MAX][c - 1 + MAX] - arr[a - 1 + MAX][b - 1 + MAX][c - 1 + MAX];
					arr[a + MAX][b + MAX][c + MAX] = temp;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[MAX * 2 + 1][MAX * 2 + 1][MAX * 2 + 1] = { 0, };
	w(arr);

	//string s;
	while (true) {
		//getline(cin, s);	// getline(cin, str, '\n');
		//if (s.length() == 0) break;
		//int a, b, c;
		//stringstream(s) >> a >> b >> c;
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		int result = arr[a + MAX][b + MAX][c + MAX];
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
	}
	return 0;
}
