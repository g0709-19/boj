#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<char> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];

	int answer = 0;
	string ppap = "pPAp";
	for (int start = 0; start + 3 < n; ++start) {
		bool has = true;
		// KMP: O(N+M)
		for (int i = 0; i < ppap.length(); ++i) {
			if (s[start + i] != ppap[i]) {
				has = false;
				break;
			}
		}
		if (has) {
			start += 3;
			++answer;
		}
	}
	cout << answer;
}
