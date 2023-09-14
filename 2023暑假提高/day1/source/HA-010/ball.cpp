#include <bits/stdc++.h>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

const int N = 200005;

int T, n, a[N], nxt[N], t[N], vis[N];

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	std::cin >> T;
	while (T--) {
		F(i, 1, n) nxt[i] = t[i] = vis[i] = 0;
		std::cin >> n;
		F(i, 1, n) std::cin >> a[i];
		dF(i, n, 1)
			nxt[i] = t[a[i]],
			t[a[i]] = i;
		int ans = 0, sum;
		F(i, 1, n) {
			if (vis[i]) continue;
			sum = 0;
			for (int j = i; nxt[j]; j = nxt[j] + 1)
				vis[j] = 1,
				sum += nxt[j] - j + 1;
			ans = std::max(ans, sum);
		}
		std::cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
