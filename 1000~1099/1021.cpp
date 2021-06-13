#include <iostream>
#include <cmath>
#include <queue>
#include <deque>

#define NOT_FOUND	-1

using namespace std;

int findIndex(deque<int> dq, int key)
{
	for (int i=0; i<dq.size(); ++i)
		if (dq[i] == key)
			return i + 1;
	return NOT_FOUND;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;		// N = Size, M = Need
	cin >> N >> M;
	queue<int> q;	// Need
	deque<int> dq;
	// Input
	for (int i=0; i<M; ++i)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	for (int i=1; i<=N; ++i) dq.push_back(i);

	int answer = 0;
	while (M--)
	{
		int _front = dq.front();
		int _top = q.front(); q.pop();
		if (_front != _top)	// Search
		{
			int key = findIndex(dq, _top);
			if (key == NOT_FOUND) exit(0);
			int op2 = key - 1;				// Move left(Front ~ Key)
			int op3 = dq.size() - key + 1;	// Move right(Key ~ Last)
			if (op2 > op3)	// op2 slower?
			{
				for (int i=0; i<op3; ++i)
				{
					int last = dq.back();
					dq.pop_back();
					dq.push_front(last);
				}
				answer += op3;
			}
			else			// op3 slower?
			{
				for (int i=0; i<op2; ++i)
				{
					int first = dq.front();
					dq.pop_front();
					dq.push_back(first);
				}
				answer += op2;
			}
		}
		dq.pop_front();
	}
	cout << answer << '\n';
	return 0;
}
