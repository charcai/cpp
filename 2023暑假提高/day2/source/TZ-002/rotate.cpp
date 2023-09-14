#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, x, p;
bool flag;

bool check(int f) {
	return (f * (f + 1) / 2 + x) % n == 0;
}

signed main() {
	freopen("rotate.in", "r", stdin);
	freopen("rotate.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		flag = false;
		scanf("%lld%lld%lld", &n, &x, &p);
		for (int i = 1; i <= p; i++)
			if (check(i)) {
				flag = true;
				break;
			}
				
		if (flag)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
