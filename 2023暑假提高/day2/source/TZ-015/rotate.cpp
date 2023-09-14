#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, x, p;

int read()
{
	int y = 0, ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		y = y * 10 + ch - '0', ch = getchar();
	return y;
}

bool solve()
{
	for (int f = 1; f <= p; f++)
		if (((f * f + f) / 2 + x) % n == 0)
			return true;
	return false;
}

signed main()
{
	freopen("rotate.in", "r", stdin);
	freopen("rotate.out", "w", stdout);
	t = read();
	while (t--)
	{
		n = read(), x = read(), p = read();
		if (solve())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
