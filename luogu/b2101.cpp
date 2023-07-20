#include <iostream>
using namespace std;

int a[101][101], m, n, sum = 0;

int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == 1 || j == 1 || i == m || j == n) {
                sum += a[i][j];
            }
        }
    }
    cout << sum << endl;
    return 0;
}