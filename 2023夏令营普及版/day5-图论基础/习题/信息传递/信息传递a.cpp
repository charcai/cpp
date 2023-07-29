#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200000 + 10;
int n;
vector<int> G[MAXN];
bool vis[MAXN];
int ans = INF;

void dfs(int x, int s, int dep)
{
	vis[x] = true;
	
	for(int i = 0; i < G[x].size(); i++)
	{
		int y = G[x][i];
		if(vis[y])
		{
			if(y == s) ans = min(ans, dep); //到达自己，出现环 
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
	
	for(int i = 1; i <= n; i++)
	{
		memset(vis,false,sizeof(vis));
		dfs(i,i,1);	
	}
	
	cout << ans << endl;
	
	return 0;
}

