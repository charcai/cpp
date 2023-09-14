#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, t, cnt, ans;

int read()
{
	int x = 0, ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

void solve(int x, int y)
{
	if (cnt + 1 == x)
	{
		cnt++;
		return;
	}
	if (cnt + y > x)
	{
		int dy = x - cnt;
		ans += (x - cnt - 1 + x - cnt - dy) * dy / 2;
		cnt += dy;
	}
	else
	{
		ans += (x - cnt - 1 + x - cnt - y) * y / 2;
		cnt += y;
	}
}

signed main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	t = read();
	while (t--)
	{
		n = read();
		map<int, int> m;
		for (int i = 1; i <= n; i++)
		{
			m[read()]++, cnt = 0, ans = 0;
			for (auto it : m)
				if (it.first > cnt)
					solve(it.first, it.second);
			printf("%d ", ans);
		}
		puts("");
	}
	return 0;
}
