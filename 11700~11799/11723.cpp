#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int M;
  ifstream input("input");
  ifstream output("output");
  cout << (((1 << 21) - 1)) << " " << (0xFFFFF) << '\n';
  input >> M;
  int S = 0;
  while (M-- != 0) {
    string command;
    int x;
    input >> command >> x;
    --x;
    if (command == "add") {
      S |= 1 << x;
    } else if (command == "remove") {
      S &= ~(1 << x);
    } else if (command == "check") {
      int check = S & 1 << x ? 1 : 0;
      int answer = 0;
      output >> answer;
      cout << check << " - " << answer << " // " << (check == answer ? "O" : "X") << '\n';
    } else if (command == "toggle") {
      S ^= 1 << x;
    } else if (command == "all") {
      S = 0xFFFFF;
    } else if (command == "empty") {
      S = 0;
    }
  }
  return 0;
}