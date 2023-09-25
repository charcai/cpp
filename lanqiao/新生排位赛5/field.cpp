#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int r1, r2, r3, r4;
    r1 = a * c;
    r2 = a * d;
    r3 = b * c;
    r4 = b * d;
    int m = max(r1, max(r2, max(r3, r4)));
    cout << m << endl;
    return 0;
}