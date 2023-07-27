#include <iostream>
using namespace std;

int dp[1005][1005], tag[1005][1005];
const int mod = 100003;

int main() {
    int n, m;
    cin >> n >> m;
    dp[0][1] = 1;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        tag[x][y] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            if(tag[i][j] == 1) {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}