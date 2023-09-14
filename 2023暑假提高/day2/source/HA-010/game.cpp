
#include <iostream>
#include <algorithm>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

typedef long long LL;
const int N = 200005;

int T, n, a[N], b[N];

int solve(int m) {
	int res = 0;
	F(i, 1, m) b[i] = a[i];
	std::sort(b + 1, b + m + 1);
	F(i, 1, m)
		if (b[i] > b[i - 1])
			res += b[i] - b[i - 1] - 1,
			b[i] = b[i - 1] + 1;
	return res;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		F(i, 1, n) std::cin >> a[i];
		F(i, 1, n) std::cout << solve(i) << " ";
		std::cout << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
