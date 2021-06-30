#include <iostream>
#define	MAX	1000001
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	char* s = new char[n];
	for (int i = 0; i < n; ++i) cin >> s[i];

	int answer = MAX;

	int start, end;
	for (start = 0; start < n; ++start)
		if (s[start] == '.') break;
	for (end = start + 1; end < n; ++end)
		if (s[end] == '.') break;

	do {
		int distance = end - start - 1;
		if (distance < answer) answer = distance;
		start = end;
		for (end += 1; end < n; ++end)
			if (s[end] == '.') break;
	} while (end + 1 < n);

	cout << answer << '\n';
	return 0;
}
