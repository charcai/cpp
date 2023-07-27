#include <iostream>
using namespace std;

int x;

int h(int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 2 * x;
    }
    if(n > 1) {
        return 2 * x * h(n - 1) - 2 * (n - 1) * h(n - 2);
    }
}

int main() {
    int n;
    cin >> n >> x;
    cout << h(n) << endl;
    return 0;
}