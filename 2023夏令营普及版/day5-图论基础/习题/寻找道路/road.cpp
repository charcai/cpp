#include <bits/stdc++.h>
using namespace std;
const int maxn=200010;
vector<int>g[maxn],rg[maxn];
int n,m,s,t;
bool vis[maxn],bad[maxn],flag;
queue<int>q;
int d[maxn];
void bfs1()
{
	memset(vis,false,sizeof(vis));
	memset(bad,true,sizeof(bad));
	q.push(t);vis[t]=true;bad[t]=false;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=0;i<rg[x].size();i++)
		{
			int y=rg[x][i];
			if(!vis[y])
			{
				q.push(y);
				vis[y]=true;
				bad[y]=false;
			}
		}
	}
}
bool check(int x)
{
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(bad[y])return false;
	}
	return true;
}
void bfs2()
{
	memset(d,0,sizeof(d));
	q.push(s);d[s]=0;
	while(q.size())
	{
		int x=q.front();q.pop();
		if(x==t)
		{
			printf("%d\n",d[t]);
			flag=true;
			break;
		}
		for(int i=0;i<g[x].size();i++)
		{
			int y=g[x][i];
			if(!d[y]&&check(y))
			{
				q.push(y);
				d[y]=d[x]+1;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	scanf("%d%d",&s,&t);
	bfs1();
	bfs2();
	if(!flag)printf("-1\n");
	return 0;
} 
