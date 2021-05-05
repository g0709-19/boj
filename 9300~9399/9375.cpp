#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n;
		cin >> n;	// 의상 수
		map<string, int> count;
		for (int j = 0; j < n; ++j) {
			string name, type;
			cin >> name >> type;
			count[type] += 1;	// 종류 별 의상 수
		}
		int answer = 1;
		for (auto iter = count.begin(); iter != count.end(); ++iter) {
			// N은 종류별 의상 수, k는 종류 개수
			// +1 해주는 이유: 그 옷을 입지 않는 경우도 포함
			// -1 해주는 이유: 모든 옷을 입지 않은 경우 제외
			// (N1+1) * (N2+1) * ... * (Nk-1 + 1) * (Nk+1) - 1
			answer *= (iter->second + 1);
		}
		cout << answer - 1 << '\n';
	}
	return 0;
}
