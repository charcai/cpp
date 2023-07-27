#include <iostream>
#include <string>
using namespace std;

string mod, a;

int main() {
    mod = "0123456789X";
    int t = 0, j = 1;
    cin >> a;
    for(int i = 0; i < 12; ++i) {
        if(a[i] == '-') {
            continue;
        }
        t += (a[i] - '0') * j;
        j++;
    }
    if(mod[t % 11] == a[12]) {
        cout << "Right" << endl;
    } 
    else {
        a[12] = mod[t % 11];
        cout << a << endl;
    }
    return 0;
}