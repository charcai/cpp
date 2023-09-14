#include <bits/stdc++.h>
using namespace std;
const int N = 105;

struct node {
	int to, val;
};

int n, m, u, v, x, minn[N];
vector<node> a[N];

void build(int x, int f) {
	for (int i = 0; i < a[x].size(); i++)
		if (a[x][i].to != f && a[x][i].val + minn[x] < minn[a[x][i].to]) {
			minn[a[x][i].to] = a[x][i].val + minn[x];
			build(a[x][i].to, x);
		}
}

int main() {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	memset(minn, 0x3f3f3f3f, sizeof(minn));
	cin >> n >> m;
	while (m--) {
		cin >> u >> v >> x;
		a[u].push_back({v, x});
		a[v].push_back({u, x});
	}
	if (a[n].size() == 0)
		puts("inf");
	else {
		minn[n] = 0;
		build(n, 0);
		for (int i = 1; i < n; i++)
			if (minn[i] == 0x3f3f3f3f) {
				puts("inf");
				return 0;
			} else
				minn[i] = min(minn[i], minn[1]);
		cout << minn[1] << ' ' << 1 << endl;
		cout << 1;
		for (int i = 1; i < n; i++)
			cout << 0;
		cout << ' ' << minn[1] << endl;
	}
	return 0;
}
/*
10010
10010
10110
11110
*/
