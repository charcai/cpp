#include <iostream>
using namespace std;

int main() {
    int x, y, n;
    cin >> n >> x >> y;
//输出同一行
    for(int i = 1; i <= n; ++i) {
        cout << '(' << x << ',' << i << ')' << ' ';
    }
    cout << endl;
//输出同一列
    for(int i = 1; i <= n; ++i) {
        cout << '(' << i << ',' << y << ')' << ' ';
    }
    cout << endl;
//输出对角线1
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i - j == x - y) {
                cout << '(' << i << ',' << j << ')' << ' ';
            }
        }
    }
    cout << endl;
//输出对角线2
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= n; ++j) {
            if(i + j == x + y) {
                cout << '(' << i << ',' << j << ')' << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}