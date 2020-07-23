#include <iostream>

using namespace std;

int main() {
    int i, T, A, B;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> T;
    for(i=0; i<T; ++i) {
        cin >> A >> B;
        cout << A+B << '\n';
    }
    return 0;
}