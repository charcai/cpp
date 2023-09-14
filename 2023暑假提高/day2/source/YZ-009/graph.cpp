#include<bits/stdc++.h>
#define ll long long
#define re register

using namespace std;

const int N = 205;

int n,m,flag,vis[N];
int a[N][N],ans[N];
int col[N],co_tot,is[N];

int fa[N];
int head[N],tot;
struct edge{
	int v,nxt;
}e[N<<1];

inline bool search(int s,int t)
{
	memset(vis,0,sizeof(vis));
	for(int k=s;k;k=ans[k]){
		if(vis[k])return 0;
		if(a[k][t])return 1;
		vis[k]=1;
	}
	return 0;
}

inline bool pd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			//cout<<search(i,j);
			if(!search(i,j))return 0;
		}
	}
	return 1;
}

inline void putt()
{
	cout<<"Yes\n";
	for( int i=1;i<=n;i++)cout<<ans[i]<<" ";
}

inline void work(int x)
{
	if(x==n+1)
	{
		//cout<<pd()<<endl;
		if(pd()&&(flag==0))
		{
			
			flag=1;
			putt();
		}
		else return;
	}
	for( int i=1;i<=n;i++)
	{
		if(a[x][i])
		{
			ans[x]=i;
			work(x+1);
			if(flag)return;
		}
	}
}

void add(int u,int v)
{
	e[++tot].nxt=head[u];
	e[tot].v=v;
	head[u]=tot;
}

void dfs(int u,int f)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f)continue;
		//cout<<v<<endl;
		if(fa[v])
		{
			int cnt=0;
			for(int k=u;k;k=fa[k]){
				
				cnt++;//cout<<1000<<endl;
				if(k==v)break;
			}
			if(cnt>co_tot)
			{
				co_tot=0;
				for(int k=u;k;k=fa[k]){
					
					col[++co_tot]=k;
					if(k==v)break;
				}
			}
			
		}
		else
		{
			fa[v]=u;
			dfs(v,u);
			fa[v]=0;
		}
	}
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	
	cin>>n>>m;
	for(re int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
		add(x,y);add(y,x);
	}
	
	if(n<=6)
	{
		work(1);
		if(!flag)cout<<"No";
		return 0;
	}
	
	fa[1]=1;	
	dfs(1,1);
	//cout<<co_tot;
	for(int i=1;i<co_tot;i++)
	{
		ans[col[i]]=col[i+1];
		is[col[i]]=1;
	}
	is[col[co_tot]]=1;	
	ans[col[co_tot]]=col[1];
	
	for(int i=1;i<=co_tot;i++)
	{
		int u=col[i];
		for(int j=1;j<=n;j++)
		{
			if(a[u][j]&&u!=j&&!is[j])
			{
				ans[j]=u;
				is[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!is[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
/*
6 8 
1 2 
2 3 
3 1 
4 5 
5 6 
1 6 
2 4 
3 4  
*/
