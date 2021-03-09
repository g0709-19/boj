#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	str = '0' + str + '\0';
	for (int i = 1; i < str.length(); ++i) {
		if (str[i]) cout << str[i];
		if (i >= 10 && i % 10 == 0)
			cout << '\n';
	}
	return 0;
}
