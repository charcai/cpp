#include <iostream>
using namespace std;

void swap(int &o1, int &o2) {
    int a = o1;
    o1 = o2;
    o2 = a;
}

int main() {
    int a, b;
    while(cin >> a >> b) {
    swap(a, b);
    cout << a << " " << b << endl;
    }
}