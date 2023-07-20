#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int m, n, cnt = 0;
    int a[101][101],
        b[101][101];
    cin >> m >> n;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {  
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> b[i][j];
        }
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(a[i][j] == b[i][j]) {
                cnt++;
            }
        } 
    }
    double rate = cnt * 1.0 / (m * n) * 100;
    printf("%.2lf\n", rate);
    return 0;
}