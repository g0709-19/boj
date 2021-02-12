#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string i, string j) {
	if (i.length() == j.length())
		return i.compare(j) < 0;
	return i.length() < j.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 입력
	vector<string> v(n);
	for (int i=0; i<n; ++i) {
		string temp;
		cin >> temp;
		if (temp.compare("") == 0) {
			--i;
			continue;
		}
		v.push_back(temp);
	}

	// 정렬
	sort(v.begin(), v.end(), compare);

	// 중복 제거
	v.erase(unique(v.begin(), v.end()), v.end());

	// 출력
	for (int i=0; i<v.size(); ++i) {
		if (v[i].length() > 0)
			cout << v[i] << "\n";
	}
	return 0;
}
