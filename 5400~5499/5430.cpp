#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

typedef vector<int> Token;

// 문자열을 구분자에 맞춰 분리
Token split(string str, char delim)
{
	Token token;
	if (str.compare("") == 0) return token;
	
	str += delim;

	int start = 0;
	for (int i = 0, size = str.size(); i < size; ++i)
	{
		if (str[i] == delim)
		{
			token.push_back(stoi(str.substr(start, i - start)));
			start = i + 1;
		}
	}
	return token;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;	// 명령어
		int N;
		cin >> N;
		deque<int> dq;
		string temp;
		cin >> temp;
		temp = temp.substr(1, temp.size() - 2);
		Token t = split(temp, ',');
		for (int i = 0; i < t.size(); ++i)
			dq.push_back(t[i]);

		bool reversed = false;
		bool error = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'R')
			{
				reversed = !reversed;
			}
			else if (s[i] == 'D')
			{
				if (dq.size() == 0)
				{
					cout << "error\n";
					error = true;
					break;
				}
				else
				{
					if (reversed)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}
		if (!error)
		{
			cout << "[";
			for (int i = 0; i < dq.size(); ++i)
			{
				if (reversed)
					cout << dq[dq.size() - i - 1];
				else
					cout << dq[i];
				if (i != dq.size() - 1)
					cout << ",";
			}
			cout << "]\n";
		}
	}
	return 0;
}
