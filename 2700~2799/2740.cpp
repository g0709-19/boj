#include <iostream>

#define MAX_LENGTH	101

using namespace std;

int A[MAX_LENGTH][MAX_LENGTH] = { 0 };
int B[MAX_LENGTH][MAX_LENGTH] = { 0 };
int C[MAX_LENGTH][MAX_LENGTH] = { 0 };

int N, M, K;

void multiple() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			for (int k = 0; k < M; ++k)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> B[i][j];
		}
	}
	multiple();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			cout << C[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
