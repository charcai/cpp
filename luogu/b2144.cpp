#include <iostream>
using namespace std;

int akm(int a, int b) {
    if(a == 0) {
        return b + 1;
    }
    if(b == 0) {
        return akm(a - 1, 1);
    }
    return akm(a - 1, akm(a, b - 1));
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << akm(a, b) << endl;
    return 0;
}