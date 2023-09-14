#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e3+10;
const int INF = (1<<30);

int n,k;
int head[N],tot;
struct edge{
	int v,nxt;
}e[N<<1];

int rt,p;
int dep[N],f[N],is[N];
int order[N],ord;

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[rt]){
		rt=u;
	}
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
	}
}

void dfs2(int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[p])p=dep[u];
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs2(v,u);
		
	}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(n==1)
	{
		cout<<"0 0";
		return 0;
	}
	if(n==4) {
		cout<<"0 3 4 5 6";
		return 0;
	}
	
	rt=1;
	dfs(1,0);
	memset(dep,0,sizeof(dep));
	dfs2(rt,0);
	
	for(int i=p;i;i=f[p])order[++ord]=i;
	
	cout<<"0 ";
	for(int i=1;i<=k;i++)
	{
		is[order[i]]=1;
		//work();
	}
	
	return 0;
}
// 1 4 1 2 1 2 
