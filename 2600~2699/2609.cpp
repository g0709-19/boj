#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;
	int result = gcd(a, b);			// 최대공약수
	int result2 = a * b / result;	// 최소공약수
	cout << result << '\n' << result2;
	return 0;
}
