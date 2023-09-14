#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t, n, a[N], dp[N];

int read()
{
	int x = 0, ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

void write(int x)
{
	if (x / 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	t = read();
	while (t--)
	{
		n = read();
		vector<int> v[n + 1];
		for (int i = 1; i <= n; i++)
			a[i] = read(), v[a[i]].push_back(i), dp[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1];
			int j = 0;
			while (v[a[i]][j] < i && j < v[a[i]].size())
				dp[i] = max(dp[i], dp[v[a[i]][j] - 1] + i - v[a[i]][j] + 1), j++;
		}
		write(dp[n]), puts("");
	}
	return 0;
}
