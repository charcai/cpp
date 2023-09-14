#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;

int t, n, x, a[N], maxn, sum, cnt;
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		maxn = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			maxn = max(maxn, x);
			sum = 0, cnt = 1;
			a[x]++;
			for (int i = 1; i <= maxn; i++)
				for (int j = 0; j < a[i]; j++) {
					if (i < cnt)
						cnt--;
					sum += i - cnt;
					if (i >= cnt)
						cnt++;
				}
			cout << sum << ' ';
		}
		cout << endl;
	}
	return 0;
}
