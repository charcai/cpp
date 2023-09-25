#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int stat[100005];
int l[100005], r[100005], x[100005];


int main() {
    ios :: sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= q; ++i) {
        cin >> l[i] >> r[i] >> x[i];
    }
    int mi = 0x7fffffff;
    for(int cn = 1; cn <= q; ++cn) {
        memset(stat, 0, sizeof(stat));
        for(int i = 1; i <= q; ++i) {
            if(i == cn) {
                continue;
            }
            int cntemp = 0;
            for(int j = 1; j <= n; ++j) {
                if(stat[i] == 0) {
                    cntemp++;
                    if(cntemp >= l[i] && cntemp <= r[i]) {
                        stat[i] = x[i];
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += stat[i];
        }
        mi = min(sum, mi);
    }
    cout << mi << endl;
    return 0;
}