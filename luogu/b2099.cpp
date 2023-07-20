#include <iostream>
using namespace std;

int a[6][6];

int main() {
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
        }
    }
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= 5; ++i) {
        int tmp = a[m][i];
        a[m][i] = a[n][i];
        a[n][i] = tmp;
    }
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}