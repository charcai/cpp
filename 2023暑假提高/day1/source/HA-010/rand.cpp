#include <bits/stdc++.h>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

typedef long long LL;
const int N = 20;
const int mod = 1000000007;

int n, m, v, a[N], d[N], inv, ans;

int qPow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = (LL) res * x % mod;
		x = (LL) x * x % mod;
		y >>= 1;
	}
	return res;
}

int sum() {
	F(i, 1, n) a[i] = (a[i - 1] + d[i]) % mod;
	int res = 1;
	F(i, 1, n) res = (LL) res * a[i] % mod;
	return res;
}
void Dfs(int cnt) {
	if (cnt == m) {
		ans = (ans + sum()) % mod;
		return;
	}
	F(i, 1, n)
		d[i] += v,
		Dfs(cnt + 1),
		d[i] -= v;
}

int main() {
	freopen("rand.in", "r", stdin);
	freopen("rand.out", "w", stdout);
	std::cin >> n >> m >> v;
	inv = qPow(qPow(n, m), mod - 2);
	F(i, 1, n)
		std::cin >> a[i],
		d[i] = a[i] - a[i - 1];
	Dfs(0);
	std::cout << (LL) ans * inv % mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
