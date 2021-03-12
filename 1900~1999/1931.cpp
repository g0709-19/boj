#include <iostream>
#include <algorithm>
#include <vector>

typedef struct M {
	int start;
	int end;
} M;

using namespace std;

bool compare(M& a, M& b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else {
		return a.end < b.end;
	}
}

int main() {
	int N;
	cin >> N;

	vector<M> meet(N);

	for (int i = 0; i < N; ++i)
		cin >> meet[i].start >> meet[i].end;

	// 종료 시간 순으로 정렬
	sort(meet.begin(), meet.end(), compare);

	int last = 0;	// 마지막 종료 시간
	int count = 0;	// 최대 회의 수

	for (int i = 0; i < N; ++i) {
		// 겹치지 않는 시간 중 가장 빨리 시작하는 회의 선택
		if (meet[i].start >= last) {
			last = meet[i].end;
			++count;
		}
	}
	
	cout << count << '\n';
	return 0;
}
