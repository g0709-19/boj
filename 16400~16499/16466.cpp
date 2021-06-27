#include <iostream>
#include <vector>

using namespace std;

typedef long long	ll;
typedef ll	Key;

class MinHeap {
public:
	int size;
	Key* element;
	MinHeap(int size) {
		this->size = 0;
		element = new Key[size + 1];
	}

	void swap(Key& a, Key& b) {
		Key temp;
		temp = a;
		a = b;
		b = temp;
	}

	// 삽입: 리프 노드에 삽입, 부모 노드와 대소 관계 비교하며 순서 정리
	void push(Key key) {
		int position = size + 1;
		while (position > 1) {
			int parent = position / 2;
			if (element[parent] > key) {
				element[position] = element[parent];
				position = parent;
			}
			else break;
		}
		element[position] = key;
		++size;
	}

	// 삭제: 리프 노드를 루트 노드에 삽입, 대소 관계 비교하며 순서 정리
	Key pop() {
		if (size == 0) return 0;
		Key deleted = element[1];
		element[1] = element[size];
		--size;
		int position = 1;
		while (1) {
			int left_child = position * 2;
			int right_child = position * 2 + 1;
			int next = position;
			// next 와 비교해주어야 하는 이유: 왼쪽, 오른쪽 자식 중 최소값을 선택해야 됨
			if (left_child <= size && element[left_child] < element[next])
				next = left_child;
			if (right_child <= size && element[right_child] < element[next])
				next = right_child;
			if (next == position) break;
			swap(element[position], element[next]);
			position = next;
		}
		return deleted;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	MinHeap h(n);
	for (int i = 0; i < n; ++i) {
		Key temp; cin >> temp;
		h.push(temp);
	}
	Key answer = 1;
	Key first = h.pop();
	while (answer >= first) {
		answer = first + 1;
		Key last = h.pop();
		if (last == 0) break;
		Key term = last - first;
		if (term > 1) break;
		first = last;
	}
	cout << answer << '\n';
	return 0;
}
