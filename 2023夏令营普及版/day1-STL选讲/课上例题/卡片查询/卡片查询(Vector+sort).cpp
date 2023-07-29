#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 5;
vector<vector<int>> a(N, vector<int>());
vector<vector<int>> b(N, vector<int>());
int n, q;

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    while (q--) {
		int op;
        cin >> op;
        if (op == 1) {
			int x, y;
            cin >> x >> y;
            a[y].push_back(x);
			b[x].push_back(y);
		}
		else if (op == 2) {
			int x;
            cin >> x;
            sort(a[x].begin(), a[x].end()); //有序数组排序的时间复杂度？
			for(auto y:a[x]) cout << y << " ";
            cout << "\n";
        }
		else{
			int x;
            cin >> x;
            sort(b[x].begin(), b[x].end());
			b[x].erase(unique(b[x].begin(), b[x].end()), b[x].end()); //unique将重复的元素移动到数组的末尾，最后再将迭代器指向第一个重复元素的下标
			for(auto y:b[x]) cout << y << " ";
            cout << "\n";
		}
	}
	return 0;
}
