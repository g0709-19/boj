#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	int count = 0;
	// 10이 몇 번 들어가는가? 2 x 5 쌍 개수
	// 쌍을 이뤄야 하니까 2의 개수, 5의 개수 중 작은 쪽 택하면 됨
	// 5의 개수가 무조건 더 적음
	// 25 는 5의 제곱수면서 5가 2번 들어가서 한 번 더 세줘야함
	for (int i = 5; i <= N; i *= 5)
		count += N / i;
	cout << count << '\n';
	return 0;
}
