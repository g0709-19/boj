#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (b % a == 0) cout << "factor\n";			// a가 b의 약수
		else if (a % b == 0) cout << "multiple\n";	// a가 b의 배수
		else cout << "neither\n";
	}
	return 0;
}
