#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 110;
const int maxm = 5010;

int n, m, ans, u[maxm], v[maxm], w[maxm];

signed main() {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(m == 0) {
		puts("inf");
		return 0;
	}
	bool f = true;
	for(int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		if(u[i] != 1 && f) f = false;
	}
	if(f) {
		ans = -1;
		for(int i = 1; i <= m; i++) {
			if(v[i] == n) {
				ans = w[i];
				break;
			}	
		}
		if(ans == -1) puts("inf");
		else {
			cout << ans << 1 << endl;
			for(int i = 1; i < n; i++) cout << 1;
			cout << 0 << " " << ans << endl;
		}
	} else puts("inf");
	return 0;
}

