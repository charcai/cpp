#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

int n, x, p, sum;

signed main() {
	freopen("rotate.in", "r", stdin);
	freopen("rotate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> x >> p;
		x = (n - x) % n;
		sum = 0;
		bool f = false;
		for(int i = 1; i <= min(p, 2 * n); i++) {
			sum += i;
			if(sum % n == x) {
				f = true;
				puts("Yes");
				break;
			}
		}
		if(!f) puts("No");
	}
	return 0;
}

