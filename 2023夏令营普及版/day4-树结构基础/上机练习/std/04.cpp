#include <bits/stdc++.h>
using namespace std;
const int N = 400007;
int n, tot;
int to[N], nxt[N], head[N];
int siz[N], son[N], fa[N], a[N];
void add (int x, int y)
{
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs (int x, int f)
{
	siz[x] = 1;
	int mx = -1;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = to[i];
		if (y == f) continue;
		fa[y] = x;
		dfs (y, x);
		siz[x] += siz[y];
		if (siz[y] > mx) mx = siz[y];
	}
	son[x] = mx;
}
int main()
{
	scanf ("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf ("%d%d", &x, &y);
		add (x, y);
		add (y, x);
	}
	dfs (1, 0);
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = head[i]; j; j = nxt[j])
			if (to[j] != i && siz[to[j]] == son[i]) a[++ans] = to[j];
		sort (a + 1, a + ans + 1);
		printf ("%d ", ans);
		for (int j = 1; j <= ans; j++) printf ("%d ", a[j]);
		printf ("\n");
	}
}