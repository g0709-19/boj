#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	while (getline(cin, str))
		cout << str << '\n';
	return 0;
}
