#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, ans[N];
bool d[N];
vector<int> e[N];

struct Node
{
	int u, v;
}a[N];

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

int bfs(int s, int notto)
{
	int res = 0;
	bool vis[N];
	queue<int> q;
	q.push(s), memset(vis, 0, sizeof vis), vis[s] = 1;
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		if (d[t]) res++;
		for (int i = 0; i < e[t].size(); i++)
			if (!vis[e[t][i]] && e[t][i] != notto)
				q.push(e[t][i]), vis[e[t][i]] = true;
	}
	return res;
}

int calc(int maxn)
{
	int rst = 0;
	for (int i = 1; i < n; i++)
		rst += abs(bfs(a[i].u, a[i].v) - bfs(a[i].v, a[i].u));
	return rst;
}

void dfs(int dep, int maxn)
{
	if (dep > maxn)
	{
		ans[maxn] = max(calc(maxn), ans[maxn]);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!d[i])
			d[i] = true, dfs(dep + 1, maxn), d[i] = false;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		e[u].push_back(v), e[v].push_back(u), a[i].u = u, a[i].v = v;
	}
	for (int i = 1; i <= n; i++)
		dfs(1, i);
	for (int i = 0; i <= n; i++)
		write(ans[i]), putchar(' ');
	return 0;
}
