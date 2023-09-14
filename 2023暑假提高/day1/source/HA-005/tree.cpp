#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	template <typename T> inline void read(T &x)
	{
		x=0;int y=1;
		char c=getchar();
		while(c<'0'||c>'9'){if(c=='-')y=-1; c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
		x*=y;
		return;
	}
	template <typename T> inline void write(T x)
	{
		if(x<0){putchar('-');x=-x;}
		if(x>9) write(x/10);
		putchar(x%10 + '0');
		return;
	}
}
using namespace IO;
#define writeln(x) write(x),putchar('\n')
#define writesp(x) write(x),putchar(' ')
#define INF 0x3f3f3f3f
#define N 5003
#define debug printf("Now is on line %d\n",__LINE__)
int n,K,siz[N],g[N],f[N][N];
vector<int> w[N];
void dfs(int id,int fa)
{
	siz[id]=1;
	for(int i=0;i<w[id].size();++i)
		if(w[id][i]!=fa){dfs(w[id][i],id);siz[id]+=siz[w[id][i]];}
	return;
}
void dp(int id,int fa)
{
	int to,op=0,st=K+siz[id]-n,ed=0;
	memset(f[id],-128,(siz[id]+1)*sizeof(int));
	f[id][0]=0;
	for(int i=0;i<w[id].size();++i)
	{
		to=w[id][i];
		if(to==fa) continue;
		dp(to,id);
		ed+=siz[to];
		for(int j=ed;j>=0;--j)
		{
			for(int k=0;k<=min(min(K,siz[to]),j);++k) f[id][j]=max(f[id][j],f[id][j-k]+f[to][k]);
		}
	}
	++ed;
	for(int i=ed;i>=1;--i) f[id][i]=max(f[id][i],f[id][i-1])+abs(K-i-i);
	f[id][0]+=K;
	return;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int u,v;
	read(n);
	for(int i=1;i<n;++i)
	{
		read(u);read(v);
		w[u].emplace_back(v);
		w[v].emplace_back(u);
	}
	dfs(1,0);
	for(K=0;K<=n;++K)
	{
		dp(1,0);
		writesp(f[1][K]-K);
	}
	return 0;
}
