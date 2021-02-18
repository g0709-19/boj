#include <iostream>
#include <cmath>

#define MAX		15	// 1 ≤ N < 15

using namespace std;

int N;
int arr[MAX] = { 0, };

// 그 행과 열을 방문할 수 있나?
bool canVisit(int column) {
	for (int i = 0; i < column; ++i) {
		// 같은 행인지
		if (arr[i] == arr[column]) return false;
		// 대각선은 행과 열의 길이가 같으면
		if (abs(column - i) == abs(arr[column] - arr[i])) return false;
	}
	return true;
}

int answer = 0;
void nqueen(int column) {
	// 끝까지 방문 성공했을 경우 횟수 셈
	if (column == N) {
		++answer;
		return;
	}
	// 행이 N갈래로 나뉨
	for (int i = 0; i < N; ++i) {
		arr[column] = i;
		// 내가 지금 방문할 곳이 틀리다면 방문X
		if (canVisit(column)) nqueen(column + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	nqueen(0);
	cout << answer;
	return 0;
}
