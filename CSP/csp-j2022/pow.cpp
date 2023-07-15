#include <iostream>
using namespace std;

long long sq(long long r) {
    return r*r;
}

long long qpow(int base, int p) {
    if(p == 0)
        return 1;
    if(p == 1)
        return base;
    long long tmp = qpow(base, p / 2);
    if(tmp == -1)
        return -1;
    if(tmp > 1e9)
        return -1;
    tmp = sq(tmp);
    if(tmp > 1e9)
        return -1;
    if(p % 2) {
        return tmp * base;
    }
    return tmp;
}

int main() {
    int a, b;
    cin >> a >> b;
    if(a == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(b > 64) {
        cout << -1 << endl;
        return 0;
    }
    cout << qpow(a, b) << endl;
    return 0;
}