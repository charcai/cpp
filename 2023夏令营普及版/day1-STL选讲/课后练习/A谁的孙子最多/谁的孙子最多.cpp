#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
vector <int> a[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		a[x].push_back(i);
	}
	int pos = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (unsigned j = 0; j < a[i].size(); j++)
			tot += a[a[i][j]].size();
		if (tot > cnt) {
			cnt = tot;
			pos = i;
		}
	}
	cout << pos << ' ' << cnt << endl;
	return 0;
}
