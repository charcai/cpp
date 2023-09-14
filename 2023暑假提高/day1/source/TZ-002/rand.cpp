#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int n, m, v, a, sum = 1;
signed main() {
	freopen("rand.in", "r", stdin);
	freopen("rand.out", "w", stdout);
	cin >> n >> m >> v;
	double x = m / n;
	for (int i = 1; i <= n; i++) {
		double a;
		cin >> a;
		a += ceil((double)x * i) * v;
		sum = (int)(sum * a) % mod;
	}
	cout << sum << endl;
	return 0;
}
