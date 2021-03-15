#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 2);
    dp[1] = 1; dp[2] = 3;
    for (int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    cout << dp[n] << '\n';
    return 0;
}
