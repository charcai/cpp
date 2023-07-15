#include <iostream>
using namespace std;

int n, h[1001], sum, cnt;
double avg;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        sum += h[i];
    }
    avg = sum * 1.0 / n;
    for(int i = 1; i <= n; ++i) {
        if(h[i] > avg) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}