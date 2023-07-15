#include <iostream>
#include <algorithm>
using namespace std;

int n, t[1005], x;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    cin >> x;
    t[0] = x;
    sort(t, t + 1 + n);
    for(int i = 0; i < n; ++i) {
        cout << t[i] << " ";
    }
    cout << t[n] << endl;
    return 0;
}