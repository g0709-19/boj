#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define COUNT_LENGTH	8001
#define BASE			4000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;			// 산술평균 계산용 합
	vector<int> arr;		// 입력받은 수 저장
	int count[COUNT_LENGTH] = {0,};	// 빈도 측정 배열

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;			// 입력
		++count[temp + BASE];	// 빈도 누적
		sum += temp;			// 합 누적
		arr.push_back(temp);	// 입력받은 값 저장
	}

	vector<int> mode;
	{
		int max = *max_element(count, count + COUNT_LENGTH);
		for (int i = 0; i < COUNT_LENGTH; ++i) {
			if (count[i] == max)
				mode.push_back(i - BASE);	// 최빈값만 걸러냄
		}
		sort(mode.begin(), mode.end());		// 오름차순 정렬
	}

	sort(arr.begin(), arr.end());			// 오름차순 정렬

	cout << round((double)sum / n) << '\n';	// 산술평균
	cout << arr[n / 2] << '\n';				// 중앙값
	
	// 최빈값
	if (mode.size() > 1)
		cout << mode[1] << '\n';
	else
		cout << mode[0] << '\n';

	int max = arr.back(), min = arr.front();// 최대, 최소값
	cout << (max - min) << '\n';			// 범위

	return 0;
}
