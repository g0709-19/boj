#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int S = 0;
  int M;
  cin >> M;
  while (M-- != 0) {
    int x;
    string command;
    cin >> command;
    if (command == "add") {
      cin >> x;
      S |= (1 << x);
    } else if (command == "remove") {
      cin >> x;
      S &= ~(1 << x);
    } else if (command == "check") {
      cin >> x;
      cout << (S & 1 << x ? 1 : 0) << '\n';
    } else if (command == "toggle") {
      cin >> x;
      S ^= (1 << x);
    } else if (command == "all") {
      S = (1 << 21) - 1;
    } else if (command == "empty") {
      S = 0;
    }
  }
  return 0;
}