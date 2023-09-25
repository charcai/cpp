#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int x, y;
        cin >> x >> y;
        if(x > y * 10) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}