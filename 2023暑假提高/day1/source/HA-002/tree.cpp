#include <bits/stdc++.h>
using namespace std;

#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
const int N=5000+5;
int n,m;
struct Edge{
	int to,nxt;
}ed[N<<1];
int head[N],tot;
inline void add(int u,int v){
	ed[++tot]=(Edge){v,head[u]},head[u]=tot;
}
int size[N];
int dp[N][2][N];
int dfs(int u,int fa)
{
	size[u]=1;
	int p=1;
	for(int i=head[u];i;i=ed[i].nxt)
	{
		int to=ed[i].to;
		if(to==fa) continue;
		int p2=dfs(to,u);
		size[u]+=size[to];
		for(register int j=0;j<=min(m,size[u]);++j)
		{
			dp[u][p][j]=0;
			for(register int k=max(0,j-(size[u]-size[to]));k<=min(j,size[to]);++k)
				dp[u][p][j]=max(dp[u][p][j],dp[to][p2][k]+dp[u][p^1][j-k]+abs(m-k-k));
		}
		p^=1;
	}
	return p^1;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		add(u,v),add(v,u);
	for(m=0;m<=n;++m)
	{
		for(register int i=0;i<=n;++i)
			for(register int j=0;j<=n;++j)
				dp[i][0][j]=dp[i][1][j]=0;
		memset(size,0,sizeof(size));
		int p=dfs(1,0);
		printf("%d ",dp[1][p][m]);
	}
	return 0;
}
