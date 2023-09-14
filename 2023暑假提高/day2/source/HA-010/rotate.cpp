#include <iostream>
#include <algorithm>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

typedef long long LL;

int T, n, x, p;

int main() {
	freopen("rotate.in", "r", stdin);
	freopen("rotate.out", "w", stdout);
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x >> p;
		bool ans = 0;
		p = std::min(n * 2, p);
		F(i, 1, p)
			if (((LL) i * (i + 1) / 2 + x) % n == 0) {
				ans = 1;
				break;
			}
		std::cout << (ans ? "Yes\n" : "No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
