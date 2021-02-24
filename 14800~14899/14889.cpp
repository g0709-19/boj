#include <iostream>
#include <vector>
#include <cmath>

#define INF	-1

using namespace std;

int N;
int** arr;

int _min = INF;

vector<int> start;
vector<int> link;

void solve(int member) {
	// 팀이 모두 나눠졌다면 능력치 계산
	if (member == N) {
		if (start.size() == N / 2 && link.size() == N / 2) {
			int start_sum = 0;
			int link_sum = 0;
			for (int i = 0; i < N / 2; ++i)
				for (int j = i + 1; j < N / 2; ++j) {
					start_sum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
					link_sum += arr[link[i]][link[j]] + arr[link[j]][link[i]];
				}
			int diff = abs(start_sum - link_sum);
			if (diff < _min || _min == INF)
				_min = diff;
		}
		return;
	}

	// member 가 start 에 있는 경우
	start.push_back(member);
	solve(member + 1);
	start.pop_back();

	// member 가 link 에 있는 경우
	link.push_back(member);
	solve(member + 1);
	link.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	arr = new int*[N];
	for (int i = 0; i < N; ++i)
		arr[i] = new int[N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	solve(0);
	cout << _min;

	for (int i = 0; i < N; ++i)
		delete[] arr[i];
	delete[] arr;
	return 0;
}
