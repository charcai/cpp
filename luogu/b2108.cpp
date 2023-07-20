#include <iostream>
#include <cmath>
using namespace std;

int mm[105][105], ans[105][105];

int main() {
    int n, m;
//input    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> mm[i][j];
        }
    }
//Process_Edge
    for(int i = 1; i <= n; ++i) {
        ans[i][1] = mm[i][1];
        ans[i][m] = mm[i][m];
    }
    for(int i = 1; i <= m; ++i) {
        ans[1][i] = mm[1][i];
        ans[n][i] = mm[n][i];
    }
//Calculate
    for(int i = 2; i < n; ++i) {
        for(int j = 2; j < m; ++j) {
            ans[i][j] = int((mm[i - 1][j] + mm[i][j - 1] + mm[i + 1][j] + mm[i][j + 1] + mm[i][j]) / 5.0 + 0.5);
        }
    }
//Print
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}