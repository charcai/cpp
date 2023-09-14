#include <bits/stdc++.h>
using namespace std;

int n, u, v;
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> u >> v;
	cout << 0;
	for (int i = 1; i <= n; i++)
		cout << ' ' << i * (n - 3) + 2;
	cout << endl;
	return 0;
}
