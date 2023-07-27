#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct person {
    int k, s;
    bool operator < (person cmp) const {
        if(s > cmp.s) {
            return true;
        }
        else {
            if(s == cmp.s) {
                if(k < cmp.k) {
                    return true;
                }
                return false;
            }
            else return false;
        }
    }
} a[5001];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].k >> a[i].s;
    }
    m = floor(m * 1.5);
    sort(a + 1, a + 1 + n);
    int fsx = a[m].s;
    int people = m;
    for(int i = m + 1; i <= n; ++i) {
        if(a[i].s == fsx) {
            people++;
        }
        else if(a[i].s < fsx) {
            break;
        }
    }
    cout << fsx << " " << people << endl;
    for(int i = 1; i <= people; ++i) {
        cout << a[i].k << " " << a[i].s << endl;
    }
    return 0;
}