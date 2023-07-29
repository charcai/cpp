#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200000 + 10;
int n;
vector<int> G[MAXN];
int vis[MAXN]; //Ê±¼ä´Á 
int ans = INF;

void dfs(int x, int dep)
{
	vis[x] = dep;
	
	for(int i = 0; i < G[x].size(); i++)
	{
		int y = G[x][i];
		if(vis[y])   
		{
			ans = min(ans, dep - vis[y] + 1);
			return;
		}
		else
		{
			dfs(y, dep + 1);
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		G[i].push_back(x);
	}
	
	memset(vis,false,sizeof(vis));
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) dfs(i,1);	
	}
	
	cout << ans << endl;
	
	return 0;
}

