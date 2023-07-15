#include <iostream>
#include <algorithm>
using namespace std;

int lim, n, v[1001], cnt, lft, rgt;

int main() {
    cin >> lim >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    lft = 1, rgt = n;
    while(lft < rgt) {
        if(v[lft] + v[rgt] > lim) {
            cnt++, rgt--;
        }
        else {
            cnt++, lft++, rgt--;
        }
    }
    if(lft == rgt) {
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}