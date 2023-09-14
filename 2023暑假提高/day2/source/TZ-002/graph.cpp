#include <bits/stdc++.h>
using namespace std;
const int N = 25;

int n, m, u, v, t[N];
bool b[N];
vector<int> a[N];

bool check(int x[]) {
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= n; i++)
		if (t[i] == 0) {
			memset(b, false, sizeof(b));
			for (int j = i; t[j] == 0; j = x[j]) {
				t[j] = 1;
				for (int k = 0; k < a[j].size(); k++)
					b[a[j][k]] = true;
			}
			for (int j = 1; j <= n; j++)
				if (i != j && !b[j])
					return false;
		}
	return true;
}

bool build(int x, int d[], int cnt) {
	if (cnt == n) {
		if (!check(d))
			return false;
		puts("Yes");
		for (int i = 1; i <= cnt; i++)
			cout << d[i] << ' ';
		cout << endl;
		return true;
	}
	if (d[x] > 0)
		return false;
	for (int i = 0; i < a[x].size(); i++) {
		d[x] = a[x][i];
		if (build(a[x][i], d, cnt + 1))
			return true;
		d[x] = 0;
	}
	return false;
}

int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
//	if (!build(1, t, 0))
		puts("No");
	return 0;
}
/*
6 7
1 2
2 3
3 1
4 5
5 6
4 6
2 5
*/
