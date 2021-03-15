#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<vector<int>> dp(2);
        for (int i = 0; i < 2; ++i) {
            dp[i] = vector<int>(n + 1);
            for (int j = 1; j <= n; ++j)
                cin >> dp[i][j];
        }
        for (int i = 2; i <= n; ++i) {
            // 대각선 1칸 뒤, 대각선 2칸 뒤 중 큰 값을 더함
            dp[0][i] += max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] += max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    return 0;
}
