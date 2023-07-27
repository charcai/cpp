#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int, int> a;
set<int> b;

int main() {
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> q;
        a[q]++;
        b.insert(q);
    }
    for(set<int>::iterator it = b.begin(); it != b.end(); ++it) {
        cout << *it << " " << a[*it] << endl;
    }
    return 0;
}