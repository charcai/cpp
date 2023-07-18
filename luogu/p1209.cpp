#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cow[201];
vector<int> sp;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int m, s, c, len;
    int maxp = 0, minp = 0x7fffffff;
    cin >> m >> s >> c;
    for(int i = 1; i <= c; ++i) {
        cin >> cow[i];
    }
    if(m > c) {
        cout << c << endl;
        return 0;
    }
    sort(cow + 1, cow + 1 + c);
    len = cow[c] - cow[1] + 1;
    for(int i = 1; i < c; ++i) {
        sp.push_back(cow[i + 1] - cow[i] - 1);
    }
    sort(sp.begin(), sp.end(), cmp);
    vector<int> :: iterator it = sp.begin();
    for(int i = 2; i <= m; ++i) {
        len = len - *it; 
        it++;
    }
    cout << len << endl;
    return 0;
}