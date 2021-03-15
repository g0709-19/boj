#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n+2);
    dp[1] = vector<int>(10);
    dp[1][0] = 1;
    for (int i = 1; i < 10; ++i) dp[1][i] = 1;
    /*
    * 끝의 자리가 0~9인 개수를 모두 따짐
    * 1 1 1 1 . . . .
    * 1 2 3 4 5 . . .
    * 1 3 6 10 . . . .
    */
    for (int i = 2; i <= n+1; ++i) {
        dp[i] = vector<int>(10);
        for (int j = 1; j < 10; ++j) {
            dp[i][j] = (dp[i][j - 1] == 0 ? 1 : dp[i][j - 1]) + dp[i - 1][j];
            dp[i][j] %= 10007;
        }
    }
    cout << dp[n+1][9] << '\n';
    return 0;
}
