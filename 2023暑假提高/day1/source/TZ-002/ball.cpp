#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

inline int read() {
	int sum = 0;
	char c = getchar();
	while (!isdigit(c))
		c = getchar();
	while (isdigit(c))
		sum = (sum << 3) + (sum << 1) + (c ^ 48), c = getchar();
	return sum;
}

inline void print(int x) {
	if (x < 10) {
		putchar(x + '0');
		return;
	}
	print(x / 10);
	putchar(x % 10 + '0');
}

int T, n, a, f[N], s[N];

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	T = read();
	while (T--) {
		memset(f, 0, sizeof(f));
		n = read();
		vector<int> d[n + 1];
		for (int i = 1; i <= n; i++) {
			a = read();
			for (int j = 0; j < d[a].size(); j++)
				f[i] = max(f[i], s[d[a][j] - 1] + i - d[a][j] + 1);
			d[a].push_back(i);
			s[i] = max(s[i - 1], f[i]);
		}
		print(s[n]);
	}
	return 0;
}
