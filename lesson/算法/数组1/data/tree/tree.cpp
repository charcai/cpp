#include <iostream>
using namespace std;

int l, m, tree1, tree2, cnt;
bool tree[10001];

int main() {

    cin >> l >> m;
    for(int i = 0; i < m; ++i) {
        cin >> tree1 >> tree2;
        for(int j = tree1; j <= tree2; ++j) {
            tree[j] = 1;
        }
    }
    for(int i = 0; i <= l; ++i) {
        cnt += !tree[i];
    }
    cout << cnt << endl;
    return 0;
}