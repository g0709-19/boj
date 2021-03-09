#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	int len_a = A.length();
	int len_b = B.length();
	int max_len = max(len_a, len_b);

	vector<int> a(max_len);
	vector<int> b(max_len);

	for (int i = 0; i < len_a; ++i)
		a[i] = A[len_a-i-1] - '0';
	for (int i = 0; i < len_b; ++i)
		b[i] = B[len_b-i-1] - '0';

	vector<int> result(max_len+1);
	
	int carry = 0;
	for (int i = 0; i < max_len; ++i) {
		int sum = a[i] + b[i] + carry;

		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		}
		else carry = 0;

		result[i] = sum;
	}
	if (carry == 1)
		result[max_len] = carry;

	bool first = true;
	for (int i = max_len; i >= 0; --i) {
		if (first && result[i] != 0)
			first = false;
		if (!first)
			cout << result[i];
	}
	cout << '\n';
	return 0;
}
