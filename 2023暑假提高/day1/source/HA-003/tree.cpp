#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 5e3 + 10;

signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if(n == 1) {
		cout << "0 0" << endl;
	} else {
		cout << 0 << " ";
		for(int i = 1; i <= n; i++) cout << n - 2 + i << " ";
		cout << endl;
	}
	return 0;
}

