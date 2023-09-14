#include <bits/stdc++.h>
using namespace std;

const int N=20+5;
int n,m,ed[N][N];
int a[N];
bool vis[N];
int xuanxue;
void dfs(int dep)
{
	++xuanxue;
	if(xuanxue>10000000)
		if(clock()*1.0/CLOCKS_PER_SEC>0.95)
			printf("No\n"),exit(0);
	if(dep==n+1)
	{
		for(register int x=1;x<=n;++x)
			for(register int y=1;y<=n;++y)
				if(x!=y)
				{
					memset(vis,0,sizeof(vis)); 
					int i=x;
					bool flag=false;
					while(!vis[i])
					{
						if(ed[y][i]){
							flag=true;
							break;
						} 
						vis[i]=true;
						i=a[i];			
					}
					if(!flag) return;
				}
		printf("Yes\n");
		for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
		exit(0);
	}
	for(register int i=1;i<=n;++i)
		if(ed[dep][i])
			a[dep]=i,
			dfs(dep+1); 
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),
		ed[u][v]=ed[v][u]=1;
	dfs(1);
	printf("No\n");
	return 0;
}
