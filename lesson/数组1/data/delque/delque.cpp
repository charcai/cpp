#include <iostream>
#include <vector>
using namespace std;

int n, x, tmp, cnt, v[10001];

int main() {
    cin >> n >> x;
    cnt = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        if(tmp != x) {
            cnt++;
            v[cnt] = tmp;
        }
    }
    for(int i = 1; i < cnt; ++i) {
        cout << v[i] << " ";
    }
    cout << v[cnt] << endl;
}