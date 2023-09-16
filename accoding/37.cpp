#include <iostream>
using namespace std;

const double real = 0.0000001;
double a, b;

int main() {
    while(cin >> a >> b) {
        if(a - b >= real) {
            cout << "woshibukezhanshengde" << endl;
        }
        else if(b - a >= real) {
            cout << "wohenbaoqian" << endl;
        }
        else {
            cout << "nakezhenchun" << endl;
        }
    }
    return 0;
}