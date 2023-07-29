#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200000 + 10;
int n;
vector<int> G[MAXN];
int vis[MAXN]; //时间戳 
int ans = INF;

int fa[MAXN];   //记录当前节点所属的根结点编号 
void dfs(int x, int s, int dep)
{
	vis[x] = dep; 
	fa[x] = s;
	
	for(int i = 0; i < G[x].size(); i++)
	{
		int y = G[x][i];
		if(vis[y])
		{
			if(fa[y] == s) ans = min(ans, dep - vis[y] + 1);
			return;
		}
		else
		{
			dfs(y, s, dep + 1);
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
		if(!vis[i]) dfs(i,i,1);	
	}
	
	cout << ans << endl;
	
	return 0;
}

