#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+500;
struct edge
{
	int to,next;
}e[N<<1];
int head[N],cnt,n,d[N],d2[N],f[N],p[N];
bool in[N];
int s,g;
int t,k,ans[N];
void add(int u,int v)
{
	e[++cnt]=(edge){v,head[u]};
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	f[u]=fa; 
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)
			continue;
		d[v]=d[u]+1;
		g=(d[g]<d[v]?v:g);
		dfs(v,u);
	}
}
void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)
			continue;
		if(!in[v])
		{
			d2[v]=d2[u]+1;
		}
		dfs2(v,u);
	}
}
int work(int u)
{
	//cout<<"*";
	while(u)
	{
		//cout<<u<<" ";
		++p[u];
		u=f[u];
	}
	int a=0;
	//cout<<k<<" ";
	for(int i=1;i<=n;++i)
		a+=abs(k-2*p[i]);//,cout<<p[i]<<" ";
	a-=abs(k-2*p[s]);
	//cout<<endl;
	return a;
}
void qwq(int h)
{
	s=h; d[s]=0; g=s;
	dfs(s,0);
	
	memset(in,0,sizeof(in));
	int i=g;
	while(i)
	{
		in[i]=1;
		i=f[i];
	}
	
	memset(d2,0,sizeof(d2));
	
	dfs2(s,0);
	
	
	queue<int>q;
	q.push(s);
	k=0;
	memset(p,0,sizeof(p));
	ans[0]=0;
	while(!q.empty())
	{
		++k;
		int u=q.front(); q.pop();
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(v==f[u])
				continue;
			q.push(v);
		}
		ans[k]=min(ans[k],work(u));
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	int u,v;
	for(int i=1;i<n;++i)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	
	s=1; d[s]=0; g=s;
	dfs(s,0);
	
	s=g; d[s]=0; g=s;
	dfs(s,0);
	
	memset(ans,0x4f,sizeof(ans));
	
	qwq(s);
	qwq(g);
	
	for(int i=0;i<=n;++i)
		cout<<ans[i]<<" ";
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
