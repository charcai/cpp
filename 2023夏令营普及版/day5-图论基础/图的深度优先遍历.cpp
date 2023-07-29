#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
int n, m;
vector<int> G[MAXN];
bool vis[MAXN];

void dfs(int x)
{
	cout << x << " ";
	vis[x] = true;
	
	for(int i = 0; i < G[x].size(); i++)
	{
		int y = G[x][i];
		if(!vis[y]) dfs(y);
	}
}

int main()
{
	memset(vis,false,sizeof(vis));
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++)
		if(!vis[i]) dfs(i);
		
	return 0;
}

