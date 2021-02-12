#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct user {
	int age;
	string name;
	int priority;
} user;

bool compare(user i, user j) {
	if (i.age == j.age)
		return i.priority < j.priority;
	return i.age < j.age;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 입력
	vector<user> v(n);
	for (int i=0; i<n; ++i) {
		int temp_age;
		string temp_name;
		cin >> temp_age >> temp_name;
		user temp;
		temp.age = temp_age;
		temp.name = temp_name;
		temp.priority = i;
		v[i] = temp;
	}

	// 정렬
	sort(v.begin(), v.end(), compare);

	// 출력
	for (int i=0; i<v.size(); ++i) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
	return 0;
}
